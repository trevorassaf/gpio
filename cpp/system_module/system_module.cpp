#include "system_module.h"

#include <system_module/phys_mem_open_exception.h>
#include <system_module/mmap_exception.h>

#include <cstdio>
 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PHYSICAL_MEMORY_PATH "/dev/mem" 

const Gpio::SystemModule::PinFunctionMap
Gpio::SystemModule::PIN_FUNCTION_MAP = {
  {Gpio::PinFunction::INPUT, 0b000},
  {Gpio::PinFunction::OUTPUT, 0b001},
  {Gpio::PinFunction::AF_0, 0b010},
  {Gpio::PinFunction::AF_1, 0b011},
  {Gpio::PinFunction::AF_2, 0b100},
  {Gpio::PinFunction::AF_3, 0b101},
  {Gpio::PinFunction::AF_4, 0b110},
  {Gpio::PinFunction::AF_5, 0b111}
};

void Gpio::SystemModule::mapGpioRegisters() {
  // Open linux physical memory device file
  _mmapedFileDescriptor = ::open(PHYSICAL_MEMORY_PATH, O_RDWR | O_SYNC);
  
  if (Gpio::PhysMemOpenException::isError(_mmapedFileDescriptor)) {
    throw Gpio::PhysMemOpenException();
  }

  // Map physical memory file to memory
  off_t offset = GPIO_BASE; 
  _mmapedFile = ::mmap(
      nullptr,
      BLOCK_SIZE,
      PROT_READ | PROT_WRITE,
      MAP_SHARED,
      _mmapedFileDescriptor,
      offset 
  ); 

  if (Gpio::MmapException::isError(_mmapedFile)) {
    throw Gpio::MmapException();
  }

  _registerBasePtr = static_cast<volatile uint32_t *>(_mmapedFile);
}

void Gpio::SystemModule::unmapGpioRegisters() {
  ::munmap(_mmapedFile, BLOCK_SIZE);
  ::close(_mmapedFileDescriptor);
}

bool Gpio::SystemModule::isBitSet(
    const Gpio::InternalPinId & pin_id,
    uint32_t offset
) {
  uint8_t pin_id_num = pin_id.getNumber();
  volatile uint64_t * pin_function_bit_field =
      reinterpret_cast<volatile uint64_t *>(_registerBasePtr + offset);

  uint64_t bit_mask = 1 << pin_id_num;
  
  return *pin_function_bit_field & bit_mask;
}

void Gpio::SystemModule::setBit(
    const Gpio::InternalPinId & pin_id,
    uint32_t offset
) {
  uint8_t pin_id_num = pin_id.getNumber();
  volatile uint64_t * pin_function_bit_field =
      reinterpret_cast<volatile uint64_t *>(_registerBasePtr + offset);
  
  uint64_t bit_mask = 1 << pin_id_num;
  *pin_function_bit_field |= bit_mask;
}

Gpio::SystemModule::SystemModule() {
  mapGpioRegisters();  
}

Gpio::SystemModule::~SystemModule() {
  unmapGpioRegisters();  
}

void Gpio::SystemModule::setPinFunction(
    const Gpio::InternalPinId & pin_id,
    Gpio::PinFunction pin_function
) {
  uint8_t pin_id_num = pin_id.getNumber(); 
  volatile uint32_t * pin_register = 
      _registerBasePtr + pin_id_num / PINS_PER_SEL_REG;

  uint8_t register_offset = pin_id_num % PINS_PER_SEL_REG;
  uint8_t left_shift = register_offset * BITS_PER_PIN;

  // Clear old function 
  uint32_t pin_function_clear_mask = ~(PIN_FUNC_CLR << left_shift);
  *pin_register &= pin_function_clear_mask;

  // Set new function
  uint8_t pin_function_field_value =
      Gpio::SystemModule::PIN_FUNCTION_MAP.at(pin_function);
  uint32_t pin_function_register_value =
      pin_function_field_value << left_shift;

  *pin_register |= pin_function_register_value;
}

bool Gpio::SystemModule::level(const Gpio::InternalPinId & pin_id) {
  return isBitSet(pin_id, LVL_OFFSET);
}

void Gpio::SystemModule::set(const Gpio::InternalPinId & pin_id) {
  setBit(pin_id, SET_OFFSET);
}

void Gpio::SystemModule::clear(const Gpio::InternalPinId & pin_id) {
  setBit(pin_id, CLR_OFFSET);
}

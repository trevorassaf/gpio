#pragma once

#include <type/internal_pin_id.h>
#include <pin/pin_function.h>
#include <util/enum_class_keyer.h>

#include <cstdint>
#include <unordered_map>

#define BCM2708_PERI_BASE 0x20000000
#define GPIO_BASE         (BCM2708_PERI_BASE + 0x200000)  // GPIO controller 
 
#define BLOCK_SIZE        (4*1024)

#define PINS_PER_SEL_REG  10

#define BITS_PER_PIN      3

#define PIN_FUNC_CLR      0b111

#define SET_OFFSET        0x1C
#define CLR_OFFSET        0x28
#define LVL_OFFSET        0x34

namespace Gpio {
  class SystemModule {
    
    private:
      typedef std::unordered_map<Gpio::PinFunction, uint8_t, Util::EnumClassKeyer> PinFunctionMap;
      static const PinFunctionMap PIN_FUNCTION_MAP;

      volatile uint32_t * _registerBasePtr;
      void * _mmapedFile;
      int _mmapedFileDescriptor;

      void mapGpioRegisters();
      void unmapGpioRegisters();

      bool isBitSet(
          const Gpio::InternalPinId & internal_pin_id,
          uint32_t offset
      );

      void setBit(
          const Gpio::InternalPinId & internal_pin_id,
          uint32_t offset
      );

    public:
      SystemModule();
      ~SystemModule();

      void setPinFunction(
          const Gpio::InternalPinId & pin_id,
          Gpio::PinFunction pin_function
      );

      bool level(const Gpio::InternalPinId & pin_id);
      void set(const Gpio::InternalPinId & pin_id);
      void clear(const Gpio::InternalPinId & pin_id);
  };
};

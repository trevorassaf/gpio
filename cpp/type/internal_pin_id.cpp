#include "internal_pin_id.h"

Gpio::InternalPinId::InternalPinId(uint8_t id_num) :
    _idNumber(id_num)
{}

uint8_t Gpio::InternalPinId::getNumber() const {
  return _idNumber;
}

bool Gpio::InternalPinId::operator==(const Gpio::InternalPinId & id) const {
  return id.getNumber() == _idNumber;
}

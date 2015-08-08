#include "external_pin_id.h"

Gpio::ExternalPinId::ExternalPinId(uint8_t id_num) :
    _idNumber(id_num)
{}

uint8_t Gpio::ExternalPinId::getNumber() const {
  return _idNumber;
}

bool Gpio::ExternalPinId::operator==(const Gpio::ExternalPinId & id) const {
  return id.getNumber() == _idNumber;
}

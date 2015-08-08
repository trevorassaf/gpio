#include "pin_config.h"

#include <stdexcept>

Gpio::PinConfig::PinConfig(
    const Gpio::InternalPinId & internal_pin_id,
    const PinFunctionMap & pin_function_map
) :
    _pinFunctionMap(pin_function_map),
    _internalPinId(internal_pin_id)
{}

Gpio::PinFunction
Gpio::PinConfig::getPinFunction(
    Gpio::PinMode pin_mode
) const {
  if (!hasPinMode(pin_mode)) {
    throw std::runtime_error("Invalid pin mode!"); 
  } 

  return _pinFunctionMap.at(pin_mode);
}

bool Gpio::PinConfig::hasPinMode(Gpio::PinMode pin_mode) const {
  return _pinFunctionMap.count(pin_mode);
}

const Gpio::InternalPinId &
Gpio::PinConfig::getInternalPinId() const {
  return _internalPinId;
}

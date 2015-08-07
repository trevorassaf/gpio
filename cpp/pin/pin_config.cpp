#include <pin_config.h>

#include <stdexcept>

Gpio::PinConfig::PinConfig(
    const Gpio::InternalPinId & internal_pin_id,
    const AlternativePinFunctionMap & alternative_pin_function_map
) :
    _internalPinId(internal_pin_id),
    _alternativePinFunctionMap(alternative_pin_function_map)
{}

Gpio::AlternativePinFunction
Gpio::PinConfig::getAlternativePinFunction(
    Gpio::PinMode pin_mode
) const {
  if (!hasPinMode(pin_mode)) {
    throw std::runtime_error("Invalid pin mode!"); 
  } 

  return _alternativePinFunctionMap.at(pin_mode);
}

bool Gpio::PinConfig::hasPinMode(Gpio::PinMode pin_mode) const {
  return _alternativePinFunctionMap.count(pin_mode);
}

const Gpio::InternalPinId &
Gpio::PinConfig::getInternalPinId() const {
  return _internalPinId;
}

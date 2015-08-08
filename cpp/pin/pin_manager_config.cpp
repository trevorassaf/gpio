#include "pin_manager_config.h"

#include <type/external_pin_id.h>

#include <stdexcept>

Gpio::PinManagerConfig::PinManagerConfig(
    const Gpio::PinManagerConfig::PinConfigMap & pin_config_map    
) :
    _pinConfigMap(pin_config_map)
{}

uint8_t Gpio::PinManagerConfig::getPinCount() const {
  return _pinConfigMap.size();
}

const Gpio::PinConfig &
Gpio::PinManagerConfig::getPinConfig(
    const Gpio::ExternalPinId & id    
) const {
  if (!hasExternalPinId(id)) {
    throw std::runtime_error("Invalid external pin id!");
  }  
  return _pinConfigMap.at(id);
}

bool Gpio::PinManagerConfig::hasExternalPinId(
    const Gpio::ExternalPinId & id    
) const {
  return _pinConfigMap.count(id);
}

const Gpio::PinManagerConfig::PinConfigMap &
Gpio::PinManagerConfig::getPinConfigMap() const {
  return _pinConfigMap;
}

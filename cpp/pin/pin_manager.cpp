#include "pin_manager.h"

#include <stdexcept>

void Gpio::PinManager::initializePinMap(
    const Gpio::PinManagerConfig pin_manager_config    
) {
  // TODO: initialize memory mapped file
  //
  const Gpio::PinManagerConfig::PinConfigMap & pin_config_map = pin_manager_config.getPinConfigMap();
  _pinMap.reserve(pin_config_map.size());
  for (const auto & pin_config_map_entry : pin_config_map) {
    _pinMan[pin_config_map_entry.first] = Gpio::Pin(pin_cofig_map_entry.second);
  }
}

Gpio::PinManager::PinManager(
    const Gpio::PinManagerConfig pin_manager_config    
) {
  initializePinMap(pin_manager_config); 
}

Gpio::PinManager::~PinManager() {
// TODO: close memory mapped file
}

bool Gpio::PinManager::hasPin(
    const Gpio::ExternalPinId & id 
) const {
  return _pinMap.count(id);
}

Gpio::Pin &
Gpio::PinManager::getPin(
    const Gpio::ExternalPinId & id    
) {
  if (!hasPin(id)) {
    throw std::runtime_error("Invalid external pin id!");
  }
  return _pinMap.at(id);
}

#include "pin_manager.h"

#include <stdexcept>

void Gpio::PinManager::initializePinMap(
    const Gpio::PinManagerConfig pin_manager_config    
) {
  const Gpio::PinManagerConfig::PinConfigMap & pin_config_map = pin_manager_config.getPinConfigMap();
  _pinMap.reserve(pin_config_map.size());
  for (const auto & pin_config_map_entry : pin_config_map) {
    _pinMap[pin_config_map_entry.first] =
        new Gpio::Pin(
            pin_config_map_entry.second,
            _systemModule    
        );
  }
}

Gpio::PinManager::PinManager(
    const Gpio::PinManagerConfig pin_manager_config    
) :
    _systemModule(new Gpio::SystemModule())
{
  initializePinMap(pin_manager_config); 
}

Gpio::PinManager::~PinManager() {
  delete _systemModule;
  _systemModule = nullptr;
  // TODO: Free Pin memory
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
  return *_pinMap.at(id);
}

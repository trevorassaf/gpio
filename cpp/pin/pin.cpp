#include "pin.h"

Gpio::Pin::Pin(
    const Gpio::PinConfig & pin_config,
    Gpio::SystemModule * system_module
) :
    _pinConfig(pin_config),
    _pinMode(Gpio::PinMode::INPUT),
    _systemModule(system_module)
{}

void Gpio::Pin::setPinMode(Gpio::PinMode pin_mode) {
  if (pin_mode != _pinMode) {
    if (!_pinConfig.hasPinMode(pin_mode)) {
      throw std::runtime_error("Invalid pin mode!");
    }
    
    _pinMode = pin_mode;
    _systemModule->setPinFunction(
        _pinConfig.getInternalPinId(),
        _pinConfig.getPinFunction(pin_mode)
    );
  }
}

bool Gpio::Pin::level() const {
  return _systemModule->level(_pinConfig.getInternalPinId());
}

void Gpio::Pin::clear() {
  _systemModule->clear(_pinConfig.getInternalPinId());
}

void Gpio::Pin::set() {
  _systemModule->set(_pinConfig.getInternalPinId());
}

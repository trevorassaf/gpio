#include "pin.h"

Gpio::Pin::Pin(
    const Gpio::PinConfig & pin_config
) :
    _pinConfig(pin_config),
    _pinMode(Gpio::PinMode::INPUT)
{
  // TODO: perform any memory calculations specific to this pin
}

Gpio::Pin::~Pin() {
  // TODO: restory any gpio register values
}

void Gpio::Pin::setPinMode(Gpio::PinMode pin_mode) {
  if (pin_mode != _pinMode) {
    _pinMode = pin_mode;
  // TODO: register pin mode change to system
  }
}

bool Gpio::Pin::level() const {
  // TODO: fetch level value
  return false;
}

void Gpio::Pin::clear() {
  // TODO: clear value
}

void Gpio::Pin::set() {
  // TODO: set value
}

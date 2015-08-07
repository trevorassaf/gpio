#pragma once

#include <pin/pin_mode.h>
#include <pin/pin_manager.h>
#include <pin/pin_config.h>

#include <cstdint>

namespace Gpio {

  class Pin {

    private:
      const Gpio::PinConfig _pinConfig;
     
      Gpio::PinMode _pinMode;
     
      friend class Gpio::PinManager;
      Pin(const Gpio::PinConfig & pin_config);
      ~Pin();

    public:
      void setPinMode(Gpio::PinMode pin_mode);
      bool level() const;
      void clear();
      void set();
  };
};

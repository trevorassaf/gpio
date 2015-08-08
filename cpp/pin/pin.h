#pragma once

#include <system_module/system_module.h>

#include <pin/pin_mode.h>
#include <pin/pin_manager.h>
#include <pin/pin_config.h>

#include <cstdint>

namespace Gpio {

  class PinManager;

  class Pin {

    private:
      const Gpio::PinConfig _pinConfig;
     
      Gpio::PinMode _pinMode;

      Gpio::SystemModule * _systemModule;
     
      friend class Gpio::PinManager;
      Pin(
          const Gpio::PinConfig & pin_config,
          Gpio::SystemModule * system_module
      );
     
    public:
      void setPinMode(Gpio::PinMode pin_mode);
      bool level() const;
      void clear();
      void set();
  };
};

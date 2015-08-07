#pragma once

#include <pin/pin_manager.h>

#include <cstdint>

namespace Gpio {
  class Pin {
    private:
      enum class PinFunction {
        READ,
        WRITE
      }; 

      PinFunction _currentPinFunction;

      const uint8_t _pinId;
     
      friend class Gpio::PinManager;
      Pin(const uint8_t pin_id);
      ~Pin();

    public:
      Pin(const Pin & pin) = delete;
      Pin & operation=(const Pin & pin) = delete;
      bool read(); 
      void write(bool value);
      void clear();
      void set();
  };
};

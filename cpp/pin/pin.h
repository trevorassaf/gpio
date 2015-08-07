#pragma once

#include <pin/pin_manager.h>

namespace Gpio {
  class Pin {
    private:
      enum class PinFunction {
        READ,
        WRITE
      }; 

      PinFunction _currentPinFunction;
     
      friend class Gpio::PinManager;
      Gpio();

    public:
      ~Gpio();
      bool read(); 
      void write(bool value);
      void clear();
      void set();
  };
};

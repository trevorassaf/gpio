#pragma once

namespace Gpio {
  class Pin {
    private:
      enum class PinFunction {
        READ,
        WRITE
      }; 

      PinFunction _currentPinFunction;

    public:
      Gpio();
  };
};

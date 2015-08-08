#pragma once

#include <pin/pin_function.h>
#include <pin/pin_mode.h>

#include <type/internal_pin_id.h>

#include <util/enum_class_keyer.h>

#include <unordered_map>

namespace Gpio {

  class PinConfig {

    public:
      typedef std::unordered_map<Gpio::PinMode, Gpio::PinFunction, Util::EnumClassKeyer> PinFunctionMap;

    private:
      const  PinFunctionMap _pinFunctionMap;
      const Gpio::InternalPinId _internalPinId;

    public:
      PinConfig(
          const Gpio::InternalPinId & internal_pin_id,
          const PinFunctionMap & pin_function_map 
      );

      Gpio::PinFunction getPinFunction(Gpio::PinMode pin_mode) const;
      bool hasPinMode(Gpio::PinMode pin_mode) const;
      const Gpio::InternalPinId & getInternalPinId() const;
  };
};

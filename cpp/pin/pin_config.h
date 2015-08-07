#pragma once

#include <pin/alternative_pin_function.h>
#include <pin/pin_mode.h>
#include <type/internal_pin_id.h>
#include <util/enum_class_keyer.h>

namespace Gpio {

  class PinConfig {

    public:
      typedef std::unordered_map<Gpio::PinMode, Gpio::AlternativePinFunction, Util::EnumClassKeyer> AlternativePinFunctionMap;

    private:
      const  AlternativePinFunctionMap _alternativePinFunctionMap;
      const Gpio::InternalPinId _internalPinId;

    public:
      PinConfig(
          const Gpio::InternalPinId & internal_pin_id,
          const AlternativePinFunctionMap & alternative_pin_function_map 
      );

      Gpio::AlternativePinFunction getAlternativePinFunction(Gpio::PinMode pin_mode) const;
      bool hasPinMode(Gpio::PinMode pin_mode) const;
      const Gpio::InternalPinId & getInternalPinId() const;
  };
};

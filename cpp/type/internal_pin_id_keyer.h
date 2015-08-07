#pragma once

#include <type/internal_pin_id.h>

namespace Gpio {
  struct InternalPinIdKeyer {
    std::size_t operator()(const Gpio::InternalPinId & id) const {
      return static_cast<std::size_t>(id.getNumber());
    }
  };
};

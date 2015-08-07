#pragma once

#include <type/external_pin_id.h>

namespace Gpio {
  struct ExternalPinIdKeyer {
    std::size_t operator()(const Gpio::ExternalPinId & id) const {
      return static_cast<std::size_t>(id.getNumber());
    }
  };
};

#pragma once

#include <cstdint>

namespace Gpio {
  class InPinId {

    private:
      const uint8_t _internalPinId;

    public:
      InPinId(uint8_t internal_pin_id);
      uint8_t getNumber() const;
  };
};

#pragma once

#include <cstdint>

namespace Gpio {
  class ExPinId {

    private:
      const uint8_t _externalPinId;

    public:
      ExPinId(uint8_t external_pin_id);
      uint8_t getNumber() const;
  };
};

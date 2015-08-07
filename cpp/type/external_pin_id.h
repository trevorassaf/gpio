#pragma once

#include <cstdint>

namespace Gpio {
  class ExternalPinId {

    private:
      const uint8_t _externalPinId;

    public:
      ExternalPinId(uint8_t external_pin_id);
      uint8_t getNumber() const;
  };
};

#pragma once

#include <cstdint>

namespace Gpio {
  class InternalPinId {

    private:
      const uint8_t _idNumber;

    public:
      InternalPinId(uint8_t internal_pin_id);
      uint8_t getNumber() const;
      bool operator==(const Gpio::InternalPinId & id) const;
  };
};

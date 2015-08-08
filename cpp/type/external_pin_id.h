#pragma once

#include <cstdint>
#include <functional>

namespace Gpio {
  class ExternalPinId {

    private:
      const uint8_t _idNumber;

    public:
      ExternalPinId(uint8_t external_pin_id);
      uint8_t getNumber() const;
      bool operator==(const ExternalPinId & id) const;
  };
};

namespace std {

  template <>
  struct hash<Gpio::ExternalPinId> {

    std::size_t operator()(const Gpio::ExternalPinId & pin_id) const {
      return static_cast<std::size_t>(pin_id.getNumber());
    }
  };
}

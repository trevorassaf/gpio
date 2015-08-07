#pragma once

#include <cstdint>
#include <unordered_map>

namespace Gpio {

  class PinManagerConfig {

    private:
      typedef std::unordered_map<uint8_t, Gpio::PinConfig> PinConfigMap;
      const PinConfigMap _pinConfigMap;

    public:
      PinManagerConfig(
          const Gpio::PinConfigMap pin_config_map    
      );

      uint8_t getPinCount() const;      
      const Gpio::PinConfig & getPinConfig(uint8_t external_pin_index) const;
  };
};

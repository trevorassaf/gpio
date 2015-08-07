#pragma once

#include <type/external_pin_id.h>
#include <type/external_pin_id_keyer.h>

#include <unordered_map>

namespace Gpio {

  class PinManagerConfig {

    public:
      typedef std::unordered_map<Gpio::ExternalPinId, Gpio::PinConfig, Gpio::ExternalPinIdKeyer> PinConfigMap;

    private:
      const PinConfigMap _pinConfigMap;

    public:
      PinManagerConfig(
          const Gpio::PinConfigMap pin_config_map    
      );

      uint8_t getPinCount() const;      
      const Gpio::PinConfig & getPinConfig(const Gpio::ExternalPinId & id) const;
      bool hasExternalPinId(const Gpio::ExternalPinId & id) const;
      const PinConfigMap & getPinConfigMap() const;
  };
};

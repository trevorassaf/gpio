#pragma once

#include <type/external_pin_id.h>
#include <type/external_pin_id_keyer.h>

#include <pin/pin.h>
#include <pin/pin_manager_config.h>
#include <pin/pin_config.h>

#include <unordered_map>

namespace Gpio {
  class PinManager {

    private:
      typedef std::unordered_map<Gpio::ExternalPinId, Gpio::Pin, Gpio::ExternalPinIdKeyer> PinMap;
      PinMap _pinMap;

      void initializePinMap(
          const Gpio::PinManagerConfig pin_manager_config    
      );

    public:
      PinManager(
          const Gpio::PinManagerConfig pin_manager_config    
      );
      ~PinManager();

      bool hasPin(const Gpio::ExternalPinId & id) const;
      Gpio::Pin & getPin(const Gpio::ExternalPinId & id);
  };
};

#pragma once

#include <type/external_pin_id.h>

#include <system_module/system_module.h>

#include <pin/pin.h>
#include <pin/pin_manager_config.h>
#include <pin/pin_config.h>

#include <unordered_map>

namespace Gpio {

  class Pin;

  class PinManager {

    private:
      typedef std::unordered_map<
          const Gpio::ExternalPinId,
          Gpio::Pin *,
          Gpio::ExternalPinIdKeyer> PinMap;

      PinMap _pinMap;

      Gpio::SystemModule * _systemModule;

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

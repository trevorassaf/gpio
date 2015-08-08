#pragma once

#include <stdexcept>

namespace Gpio {
  class MmapException : public std::runtime_error {
    
    public:
      static bool isError(const void * map_ptr);
      MmapException();
  };
};

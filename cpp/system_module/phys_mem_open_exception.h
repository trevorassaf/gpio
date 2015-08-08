#pragma once

#include <stdexcept>

namespace Gpio {
  
  class PhysMemOpenException : public std::runtime_error {

    private:
      static int ERROR_CODE;

    public:
      static bool isError(int phys_mem_fd);
      PhysMemOpenException();
  };
};

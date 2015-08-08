#include "phys_mem_open_exception.h"

#include <cerrno>
#include <cstring>

int Gpio::PhysMemOpenException::ERROR_CODE = -1;

bool Gpio::PhysMemOpenException::isError(int phys_mem_fd) {
  return phys_mem_fd == Gpio::PhysMemOpenException::ERROR_CODE; 
}

Gpio::PhysMemOpenException::PhysMemOpenException() : 
    std::runtime_error(::strerror(errno)) {}

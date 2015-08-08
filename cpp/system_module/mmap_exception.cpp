#include "mmap_exception.h"

#include <cerrno>
#include <cstring>

#include <sys/mman.h>

bool Gpio::MmapException::isError(const void * map_ptr) {
  return map_ptr == MAP_FAILED;  
}

Gpio::MmapException::MmapException() :
    std::runtime_error(::strerror(errno)) {}

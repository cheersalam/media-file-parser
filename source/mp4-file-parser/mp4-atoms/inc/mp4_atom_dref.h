#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomDref :
        public Mp4Atom
    {
    public:
        Mp4AtomDref::Mp4AtomDref(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomDref::Mp4AtomDref(uint32_t size, char *payload);
        ~Mp4AtomDref();
    };
} //namespace mp4atom

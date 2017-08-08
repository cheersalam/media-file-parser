#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStbl :
        public Mp4Atom
    {
    public:
        Mp4AtomStbl::Mp4AtomStbl(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStbl::Mp4AtomStbl(uint32_t size, char *payload);
        ~Mp4AtomStbl();
    };
} //namespace mp4atom

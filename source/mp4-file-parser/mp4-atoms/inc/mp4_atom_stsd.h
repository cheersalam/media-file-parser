#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStsd :
        public Mp4Atom
    {
    public:
        Mp4AtomStsd::Mp4AtomStsd(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStsd::Mp4AtomStsd(uint32_t size, char *payload);
        ~Mp4AtomStsd();
    };
} //namespace mp4atom

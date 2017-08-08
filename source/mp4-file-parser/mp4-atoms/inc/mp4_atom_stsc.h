#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStsc :
        public Mp4Atom
    {
    public:
        Mp4AtomStsc::Mp4AtomStsc(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStsc::Mp4AtomStsc(uint32_t size, char *payload);
        ~Mp4AtomStsc();
    };
} //namespace mp4atom

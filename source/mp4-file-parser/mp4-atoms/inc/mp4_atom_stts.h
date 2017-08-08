#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStts :
        public Mp4Atom
    {
    public:
        Mp4AtomStts::Mp4AtomStts(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStts::Mp4AtomStts(uint32_t size, char *payload);
        ~Mp4AtomStts();
    };
} //namespace mp4atom

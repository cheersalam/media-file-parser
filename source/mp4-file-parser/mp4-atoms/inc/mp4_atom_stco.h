#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStco :
        public Mp4Atom
    {
    public:
        Mp4AtomStco::Mp4AtomStco(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStco::Mp4AtomStco(uint32_t size, char *payload);
        ~Mp4AtomStco();
    };
} //namespace mp4atom

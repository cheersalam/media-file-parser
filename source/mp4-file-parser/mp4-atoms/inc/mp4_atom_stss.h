#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStss :
        public Mp4Atom
    {
    public:
        Mp4AtomStss::Mp4AtomStss(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStss::Mp4AtomStss(uint32_t size, char *payload);
        ~Mp4AtomStss();
    };
} //namespace mp4atom

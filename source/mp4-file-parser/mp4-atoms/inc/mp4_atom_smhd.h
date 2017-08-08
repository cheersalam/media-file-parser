#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomSmhd :
        public Mp4Atom
    {
    public:
        Mp4AtomSmhd::Mp4AtomSmhd(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomSmhd::Mp4AtomSmhd(uint32_t size, char *payload);
        ~Mp4AtomSmhd();
    };
} //namespace mp4atom

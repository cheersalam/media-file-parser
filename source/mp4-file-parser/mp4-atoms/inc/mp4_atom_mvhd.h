#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomMvhd :
        public Mp4Atom
    {
    public:
        Mp4AtomMvhd::Mp4AtomMvhd(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomMvhd::Mp4AtomMvhd(uint32_t size, char *payload);
        ~Mp4AtomMvhd();
    };
} //namespace mp4atom

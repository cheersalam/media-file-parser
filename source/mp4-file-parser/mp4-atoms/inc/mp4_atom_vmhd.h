#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomVmhd :
        public Mp4Atom
    {
    public:
        Mp4AtomVmhd::Mp4AtomVmhd(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomVmhd::Mp4AtomVmhd(uint32_t size, char *payload);
        ~Mp4AtomVmhd();
    };
} //namespace mp4atom

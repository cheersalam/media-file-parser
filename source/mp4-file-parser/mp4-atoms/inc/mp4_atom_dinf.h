#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomDinf :
        public Mp4Atom
    {
    public:
        Mp4AtomDinf::Mp4AtomDinf(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomDinf::Mp4AtomDinf(uint32_t size, char *payload);
        ~Mp4AtomDinf();
    };
} //namespace mp4atom

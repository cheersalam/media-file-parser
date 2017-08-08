#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomStsz :
        public Mp4Atom
    {
    public:
        Mp4AtomStsz::Mp4AtomStsz(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomStsz::Mp4AtomStsz(uint32_t size, char *payload);
        ~Mp4AtomStsz();
    };
} //namespace mp4atom

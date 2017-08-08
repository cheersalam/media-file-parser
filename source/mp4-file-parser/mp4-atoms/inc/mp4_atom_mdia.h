#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomMdia :
        public Mp4Atom
    {
    public:
        Mp4AtomMdia::Mp4AtomMdia(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomMdia::Mp4AtomMdia(uint32_t size, char *payload);
        ~Mp4AtomMdia();
    };
} //namespace mp4atom

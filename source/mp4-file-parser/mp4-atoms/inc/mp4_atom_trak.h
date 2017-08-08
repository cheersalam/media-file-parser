#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomTrak :
        public Mp4Atom
    {
    public:
        Mp4AtomTrak::Mp4AtomTrak(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomTrak::Mp4AtomTrak(uint32_t size, char *payload);
        ~Mp4AtomTrak();
    };
} //namespace mp4atom

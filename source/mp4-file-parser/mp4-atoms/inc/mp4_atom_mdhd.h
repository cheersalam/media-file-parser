#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomMdhd :
        public Mp4Atom
    {
    public:
        Mp4AtomMdhd::Mp4AtomMdhd(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomMdhd::Mp4AtomMdhd(uint32_t size, char *payload);
        ~Mp4AtomMdhd();
    };
} //namespace mp4atom

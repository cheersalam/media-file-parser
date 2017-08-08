#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomAvcC :
        public Mp4Atom
    {
    public:
        Mp4AtomAvcC::Mp4AtomAvcC(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomAvcC::Mp4AtomAvcC(uint32_t size, char *payload);
        ~Mp4AtomAvcC();
    };
} //namespace mp4atom

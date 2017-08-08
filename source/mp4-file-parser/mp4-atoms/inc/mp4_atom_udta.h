#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomUdta :
        public Mp4Atom
    {
    public:
        Mp4AtomUdta::Mp4AtomUdta(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomUdta::Mp4AtomUdta(uint32_t size, char *payload);
        ~Mp4AtomUdta();
    };
} //namespace mp4atom

#pragma once
#include "mp4_atom.h"
#include "mp4_atom_dumm.h"

namespace mp4atom {
    class Mp4AtomDumm :
        public Mp4Atom
    {
    public:
        Mp4AtomDumm::Mp4AtomDumm(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomDumm::Mp4AtomDumm(uint32_t size, char *payload);
        ~Mp4AtomDumm();
    };
} //namespace mp4atom

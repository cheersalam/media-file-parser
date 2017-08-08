#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomUkwn :
        public Mp4Atom
    {
    public:
        Mp4AtomUkwn::Mp4AtomUkwn(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomUkwn::Mp4AtomUkwn(uint32_t size, char *payload);
        ~Mp4AtomUkwn();
    };
} //namespace mp4atom

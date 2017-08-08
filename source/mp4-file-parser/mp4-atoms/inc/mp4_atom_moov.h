#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomMoov :
        public Mp4Atom
    {
    public:
        Mp4AtomMoov::Mp4AtomMoov(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomMoov::Mp4AtomMoov(uint32_t size, char *payload);
        ~Mp4AtomMoov();

      /*  __override const char atom_type_str_[4] = { 'm', 'o', 'o', 'v' };
        __override const bool can_have_children_ = false;*/
    };
} //namespace mp4atom


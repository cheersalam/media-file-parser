#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomMdat :
        public Mp4Atom
    {
    public:
        Mp4AtomMdat::Mp4AtomMdat(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomMdat::Mp4AtomMdat(uint32_t size, char *payload);
        ~Mp4AtomMdat();

       /* __override const char atom_type_str_[4] = { 'm', 'd', 'a', 't' };
        __override const bool can_have_children_ = false;*/
    };
}


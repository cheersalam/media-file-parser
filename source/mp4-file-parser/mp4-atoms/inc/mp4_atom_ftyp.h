#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomFtyp : 
        public Mp4Atom
    {
    public:
        Mp4AtomFtyp::Mp4AtomFtyp(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomFtyp::Mp4AtomFtyp(uint32_t size, char *payload);
        ~Mp4AtomFtyp();

    public:
       // __override const char atom_type_str_[4] = { 'f', 't', 'y', 'p' };
       // __override const bool can_have_children_ = false;
    };
} //namespace mp4atom

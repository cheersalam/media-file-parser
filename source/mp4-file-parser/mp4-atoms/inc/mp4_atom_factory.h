#pragma once
#include "mp4_atom.h"
#include "mp4_atom_moov.h"

namespace mp4atom {
    class Mp4AtomFactory
    {
    public:
        Mp4AtomFactory();
        ~Mp4AtomFactory();
        static mp4atom::Mp4Atom *CreateAtom(uint32_t type, uint32_t size, char *payload);
        static mp4atom::Mp4Atom *CreateAtom(uint32_t type, uint32_t size, uint8_t version, uint32_t flags, char *payload);
    };
} //namespace mp4atom


#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomAvc1 :
        public Mp4Atom
    {
    public:
        Mp4AtomAvc1::Mp4AtomAvc1(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomAvc1::Mp4AtomAvc1(uint32_t size, char *payload);
        ~Mp4AtomAvc1();
    };
} //namespace mp4atom

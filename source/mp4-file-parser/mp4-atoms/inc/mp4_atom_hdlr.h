#pragma once
#include "mp4_atom.h"

namespace mp4atom {
    class Mp4AtomHdlr :
        public Mp4Atom
    {
    public:
        Mp4AtomHdlr::Mp4AtomHdlr(uint32_t size, uint8_t version, uint32_t flags);
        Mp4AtomHdlr::Mp4AtomHdlr(uint32_t size, char *payload);
        ~Mp4AtomHdlr();
    };
} //namespace mp4atom

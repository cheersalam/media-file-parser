#include <iostream>
#include "../inc/mp4_atom_ftyp.h"


namespace mp4atom {
    Mp4AtomFtyp::Mp4AtomFtyp(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_FTYP, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "ftyp", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomFtyp::Mp4AtomFtyp(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_FTYP, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "ftyp", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomFtyp::~Mp4AtomFtyp()
    {
    }
}

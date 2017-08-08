#include "../inc/mp4_atom_mdhd.h"


namespace mp4atom {
    Mp4AtomMdhd::Mp4AtomMdhd(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_MDHD, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMdhd::Mp4AtomMdhd(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_MDHD, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMdhd::~Mp4AtomMdhd()
    {
    }
}

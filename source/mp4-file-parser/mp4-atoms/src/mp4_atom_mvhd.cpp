#include "../inc/mp4_atom_mvhd.h"


namespace mp4atom {
    Mp4AtomMvhd::Mp4AtomMvhd(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_MVHD, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mvhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMvhd::Mp4AtomMvhd(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_MVHD, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mvhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMvhd::~Mp4AtomMvhd()
    {
    }
}

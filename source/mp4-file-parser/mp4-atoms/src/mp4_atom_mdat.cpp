#include "../inc/mp4_atom_mdat.h"

namespace mp4atom {

    Mp4AtomMdat::Mp4AtomMdat(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(ATOM_TYPE_MDAT, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdat", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMdat::Mp4AtomMdat(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_MDAT, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdat", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomMdat::~Mp4AtomMdat()
    {
    }
}

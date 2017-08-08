#include "../inc/mp4_atom_mdia.h"


namespace mp4atom {
    Mp4AtomMdia::Mp4AtomMdia(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_MDIA, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdia", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomMdia::Mp4AtomMdia(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_MDIA, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "mdia", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomMdia::~Mp4AtomMdia()
    {
    }
}

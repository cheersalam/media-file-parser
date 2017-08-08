#include "../inc/mp4_atom_stsz.h"


namespace mp4atom {
    Mp4AtomStsz::Mp4AtomStsz(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_STSZ, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsz", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsz::Mp4AtomStsz(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_STSZ, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsz", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsz::~Mp4AtomStsz()
    {
    }
}

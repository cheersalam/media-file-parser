#include "../inc/mp4_atom_ukwn.h"


namespace mp4atom {
    Mp4AtomUkwn::Mp4AtomUkwn(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_AVC1, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "ukwn", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomUkwn::Mp4AtomUkwn(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_AVC1, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "ukwn", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomUkwn::~Mp4AtomUkwn()
    {
    }
}

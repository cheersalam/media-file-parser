#include "../inc/mp4_atom_udta.h"


namespace mp4atom {
    Mp4AtomUdta::Mp4AtomUdta(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_UDTA, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "udta", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomUdta::Mp4AtomUdta(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_UDTA, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "udta", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomUdta::~Mp4AtomUdta()
    {
    }
}

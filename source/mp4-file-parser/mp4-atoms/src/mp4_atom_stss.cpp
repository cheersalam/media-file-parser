#include "../inc/mp4_atom_stss.h"


namespace mp4atom {
    Mp4AtomStss::Mp4AtomStss(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_STSS, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stss", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStss::Mp4AtomStss(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_STSS, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stss", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStss::~Mp4AtomStss()
    {
    }
}

#include "../inc/mp4_atom_stsc.h"


namespace mp4atom {
    Mp4AtomStsc::Mp4AtomStsc(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_STSC, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsc", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsc::Mp4AtomStsc(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_STSC, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsc", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsc::~Mp4AtomStsc()
    {
    }
}

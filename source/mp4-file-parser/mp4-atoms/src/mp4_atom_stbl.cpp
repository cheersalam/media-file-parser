#include "../inc/mp4_atom_stbl.h"


namespace mp4atom {
    Mp4AtomStbl::Mp4AtomStbl(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_STBL, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stbl", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomStbl::Mp4AtomStbl(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_STBL, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stbl", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomStbl::~Mp4AtomStbl()
    {
    }
}

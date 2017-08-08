#include "../inc/mp4_atom_stsd.h"


namespace mp4atom {
    Mp4AtomStsd::Mp4AtomStsd(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_STSD, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsd::Mp4AtomStsd(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_STSD, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "stsd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomStsd::~Mp4AtomStsd()
    {
    }
}

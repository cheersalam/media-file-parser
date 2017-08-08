#include "../inc/mp4_atom_smhd.h"


namespace mp4atom {
    Mp4AtomSmhd::Mp4AtomSmhd(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_SMHD, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "smhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomSmhd::Mp4AtomSmhd(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_VMHD, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "smhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomSmhd::~Mp4AtomSmhd()
    {
    }
}

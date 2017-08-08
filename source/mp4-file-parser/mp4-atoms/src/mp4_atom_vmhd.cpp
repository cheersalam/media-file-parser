#include "../inc/mp4_atom_vmhd.h"


namespace mp4atom {
    Mp4AtomVmhd::Mp4AtomVmhd(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_VMHD, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "vmhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomVmhd::Mp4AtomVmhd(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_VMHD, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "vmhd", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomVmhd::~Mp4AtomVmhd()
    {
    }
}

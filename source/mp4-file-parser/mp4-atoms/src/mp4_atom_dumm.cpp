#include "../inc/mp4_atom_dumm.h"


namespace mp4atom {
    Mp4AtomDumm::Mp4AtomDumm(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_DUMM, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "dumm", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomDumm::Mp4AtomDumm(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_DUMM, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "dumm", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomDumm::~Mp4AtomDumm()
    {
    }
}

#include "../inc/mp4_atom_avc1.h"


namespace mp4atom {
    Mp4AtomAvc1::Mp4AtomAvc1(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_AVC1, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "avc1", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomAvc1::Mp4AtomAvc1(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_AVC1, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "avc1", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomAvc1::~Mp4AtomAvc1()
    {
    }
}

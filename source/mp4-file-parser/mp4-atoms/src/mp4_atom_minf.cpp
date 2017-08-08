#include "../inc/mp4_atom_minf.h"


namespace mp4atom {
    Mp4AtomMinf::Mp4AtomMinf(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_MINF, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "minf", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomMinf::Mp4AtomMinf(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_MINF, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "minf", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = true;
    }

    Mp4AtomMinf::~Mp4AtomMinf()
    {
    }
}

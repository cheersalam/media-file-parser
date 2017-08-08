#include "../inc/mp4_atom_dref.h"


namespace mp4atom {
    Mp4AtomDref::Mp4AtomDref(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_DREF, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "dref", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomDref::Mp4AtomDref(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_DREF, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "dref", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomDref::~Mp4AtomDref()
    {
    }
}

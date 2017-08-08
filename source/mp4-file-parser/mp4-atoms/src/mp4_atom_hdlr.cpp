#include "../inc/mp4_atom_hdlr.h"


namespace mp4atom {
    Mp4AtomHdlr::Mp4AtomHdlr(uint32_t size, uint8_t version, uint32_t flags) :
        Mp4Atom(mp4atom::ATOM_TYPE_HDLR, size, version, flags)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "hdlr", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomHdlr::Mp4AtomHdlr(uint32_t size, char * payload) :
        Mp4Atom(ATOM_TYPE_HDLR, size, payload)
    {
        atomTypeStr_ = new char[5];
        memcpy(atomTypeStr_, "hdlr", 4);
        atomTypeStr_[4] = '\0';
        canHaveChildren_ = false;
    }

    Mp4AtomHdlr::~Mp4AtomHdlr()
    {
    }
}

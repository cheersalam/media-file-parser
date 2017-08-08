#include <iostream>
#include "../inc/mp4_atom.h"


namespace mp4atom {
    Mp4Atom::Mp4Atom(uint32_t atom_type, char *payload) : 
        atomType_(atom_type),
        payload_(payload)
    {
    }

    Mp4Atom::Mp4Atom(uint32_t atom_type, uint32_t size, char *payload) :
        atomType_(atom_type),
        size_(size),
        extSize_(0),
        version_(0),
        flags_(0),
        payload_(payload)
    {
    }

    Mp4Atom::Mp4Atom(uint32_t atom_type, uint32_t size, uint8_t version, uint32_t flags) :
        atomType_(atom_type),
        size_(size),
        extSize_(0),
        version_(version),
        flags_(flags),
        payload_(NULL)
    {
    }

    Mp4Atom::Mp4Atom(uint32_t atom_type, uint64_t ext_size, uint8_t version, uint32_t flags) :
        atomType_(atom_type),
        size_(0),
        extSize_(ext_size),
        version_(version),
        flags_(flags),
        payload_(NULL)
    {
    }

    Mp4Atom::~Mp4Atom()
    {
        if (payload_ != NULL) {
            delete payload_;
            payload_ = NULL;
        }
    }

    void Mp4Atom::PrintAtom()
    {
        std::cout << "*****************************************************" << std::endl;
        std::cout << "Atom Type                 : " << atomTypeStr_ << std::endl;
        std::cout << "Atom Size                 : " << size_ << std::endl;
        std::cout << "Atom Version              : " << version_ << std::endl;
        std::cout << "Atom Flags:               : " << flags_ << std::endl;
        std::cout << "Atom can have Children:   : " << canHaveChildren_ << std::endl;
        std::cout << "Atom Childs:              : " << hasChildren_ << std::endl;
        std::cout << "*****************************************************" << std::endl;
    }
}


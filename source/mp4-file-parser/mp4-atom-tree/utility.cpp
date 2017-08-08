#include "utility.h"
#include <cstdint>
#include <new>

namespace mp4atom {
    utility::utility()
    {
    }


    utility::~utility()
    {
    }

    char * utility::allocateMemory(uint64_t size)
    {
        try {
            return new char[size];
        }
        catch (std::bad_alloc& ba)
        {
            return nullptr;
        }
    }
}

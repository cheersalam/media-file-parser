#pragma once
#include <cstdint>

namespace mp4atom {
    class utility
    {
    public:
        utility();
        ~utility();
        static char* allocateMemory(uint64_t size);
    };
}


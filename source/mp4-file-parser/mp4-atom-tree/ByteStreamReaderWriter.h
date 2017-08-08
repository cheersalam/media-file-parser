#pragma once
#include <string>
#include <fstream>

enum Mode {
    READ,
    WRITE
};

class ByteStreamReaderWriter
{
public:
    ByteStreamReaderWriter();
    ~ByteStreamReaderWriter();

    
    int Open(std::string fileName, Mode mode);
    int Close();
    int Write(const char* buffer, size_t bufferLen);
    bool isEOF() const;
    int GetBytesReadCount() const;
    int GetNext4ByteToInt(int32_t *val);
    int GetNext4ByteToCharArray(char * val);
    int GetNext4ByteToUint(uint32_t *val);
    static int Convert4ByteToUint(unsigned char* str, uint32_t* val);
    int GetNextXByteToChar(char * ch, uint32_t x);
    int ReadRemainingFile(char** ch, uint64_t* size);
    int GetNext1ByteToUchar(char ch);
    int GetNext1ByteToInt(int32_t ch);

private:
    std::string fileName_;
    std::ifstream fileRead_;
    std::ofstream fileWrite_;

};


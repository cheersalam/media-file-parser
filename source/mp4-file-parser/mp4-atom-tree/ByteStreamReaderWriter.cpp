#include <iostream>
#include "ByteStreamReaderWriter.h"
#include "utility.h"


ByteStreamReaderWriter::ByteStreamReaderWriter()
{
}


ByteStreamReaderWriter::~ByteStreamReaderWriter()
{
    Close();
}

int ByteStreamReaderWriter::Open(std::string fileName, Mode mode)
{
    if (mode == Mode::READ) {
        fileRead_.open(fileName, std::ios::binary);
        if (fileRead_.fail())
        {
            // size_t errmsglen = 1024;
            char errmsg[1024];
            strerror_s(errmsg, 1024, errno);
            std::cout << "Error: " << errmsg;
            return 1;
        }
    }
    if (mode == Mode::WRITE) {
        fileWrite_.open(fileName, std::ios::binary | std::ios::out);
        if (fileWrite_.fail())
        {
            // size_t errmsglen = 1024;
            char errmsg[1024];
            strerror_s(errmsg, 1024, errno);
            std::cout << "Error: " << errmsg;
            return 1;
        }
        
    }
    return 0;
}

int ByteStreamReaderWriter::Close()
{
    fileWrite_.flush();
    fileRead_.close();
    fileWrite_.close();
    return 0;
}

int ByteStreamReaderWriter::Write(const char *buffer, size_t bufferLen)
{
    fileWrite_.write(buffer, bufferLen);
    fileWrite_.flush();
    return fileWrite_.fail();
}

bool ByteStreamReaderWriter::isEOF() const
{
    return fileRead_.eof();
}

int ByteStreamReaderWriter::GetBytesReadCount() const
{
    return fileRead_.gcount();
}


int ByteStreamReaderWriter::GetNext4ByteToInt(int32_t *val)
{
    char str[4] = {0, 0, 0, 0};
    fileRead_.read(str, 4);
    *val = ((str[0] << 24) | (str[1] << 16) | (str[2] << 8) | str[3]);
    return 0;
}

int ByteStreamReaderWriter::GetNext4ByteToCharArray(char *val)
{
    fileRead_.read(val, 4);
    return 0;
}

int ByteStreamReaderWriter::GetNext4ByteToUint(uint32_t * val)
{
    unsigned char str[4] = { 0, 0, 0, 0 };
    fileRead_.read(reinterpret_cast<char *>(str), 4);
    //*val = ((static_cast<unsigned char>(str[0]) << 24) | (static_cast<unsigned char>(str[1]) << 16) | static_cast<unsigned char>((str[2]) << 8) | static_cast<unsigned char>(str[3]));
    *val = (((str[0]) << 24) | ((str[1]) << 16) | ((str[2]) << 8) | (str[3]));
    return 0;
}

int ByteStreamReaderWriter::Convert4ByteToUint(unsigned char *str, uint32_t * val)
{
    *val = (((str[0]) << 24) | ((str[1]) << 16) | ((str[2]) << 8) | (str[3]));
    return 0;
}

int ByteStreamReaderWriter::GetNextXByteToChar(char *ch, uint32_t x)
{   
    if (ch == nullptr)
    {
        return 1;
    }
    try {
        fileRead_.read(ch, x);
        return isEOF();
    }
    catch (std::ifstream::failure e)
    {
        return 1;
    }
}

int ByteStreamReaderWriter::ReadRemainingFile(char **bufferRem, uint64_t  *size)
{
    auto const startPos = fileRead_.tellg();
    fileRead_.ignore(std::numeric_limits<std::streamsize>::max());
    auto const charCount = fileRead_.gcount();
    fileRead_.seekg(startPos);

    auto buffer = mp4atom::utility::allocateMemory(charCount);
    if (buffer != nullptr) {
        fileRead_.read(buffer, charCount);
    }
    bufferRem = &buffer;
    return 0;
}

int ByteStreamReaderWriter::GetNext1ByteToUchar(char ch)
{
    return 0;
}

int ByteStreamReaderWriter::GetNext1ByteToInt(int32_t ch)
{
    return 0;
}

#pragma once
#include <string>

class IMediaParserInterface
{
public:
    virtual ~IMediaParserInterface() = default;
    virtual int ParserMp4File(std::string filePath) = 0;
    virtual int PrintAtomTree() = 0;
    virtual int CreateNewMp4File(std::string filePath) = 0;
    virtual int ReleaseMp4Atoms() = 0;
};

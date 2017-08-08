#pragma once
#include "media-parser-interface.h"
#include "../../../../source/mp4-file-parser/mp4-atom-tree/mp4_atom_tree.h"


class MediaParserInterface : public IMediaParserInterface
{
public:
    MediaParserInterface();
    ~MediaParserInterface();
    int ParserMp4File(std::string filePath) override;
    int PrintAtomTree() override;
    int CreateNewMp4File(std::string filePath) override;
    int ReleaseMp4Atoms();
private :
    mp4atom::Mp4AtomTree *mp4AtomTree;
};


extern "C" inline __declspec(dllexport) IMediaParserInterface* __cdecl create_MediaParserInterface()
{
    return new MediaParserInterface;
}
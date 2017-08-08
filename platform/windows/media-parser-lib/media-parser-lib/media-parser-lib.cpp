// media-parser-lib.cpp : Defines the exported functions for the DLL application.
//

#include "media-parser-lib.h"

MediaParserInterface::MediaParserInterface()
{
    mp4AtomTree = new mp4atom::Mp4AtomTree();
}

MediaParserInterface::~MediaParserInterface()
{
    if (mp4AtomTree)
    {
        delete mp4AtomTree;
    }
}

int MediaParserInterface::ParserMp4File(std::string filePath)
{
    return mp4AtomTree->CreateAtomTree(filePath);
}

int MediaParserInterface::PrintAtomTree()
{
    return mp4AtomTree->PrintAtomTree();
}

int MediaParserInterface::CreateNewMp4File(std::string filePath)
{
    return mp4AtomTree->CreateNewMp4File(filePath);
}

int MediaParserInterface::ReleaseMp4Atoms()
{
    return mp4AtomTree->FreeAtomTree();
}



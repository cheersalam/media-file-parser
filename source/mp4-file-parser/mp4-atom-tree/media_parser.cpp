// MediaParser.cpp : Defines the entry point for the console application.
//

#include "mp4_atom_tree.h"

int main()
{
    mp4atom::Mp4AtomTree *mp4AtomTree = new mp4atom::Mp4AtomTree();
    int x = mp4AtomTree->CreateAtomTree("input1.mp4");
    x = mp4AtomTree->PrintAtomTree();
    mp4AtomTree->CreateNewMp4File("test1.mp4");

    mp4AtomTree->CreateAtomTree("input2.mp4");
    mp4AtomTree->PrintAtomTree();
    mp4AtomTree->CreateNewMp4File("test2.mp4");

    mp4AtomTree->CreateAtomTree("input3.mp4");
    mp4AtomTree->PrintAtomTree();
    mp4AtomTree->CreateNewMp4File("test3.mp4");
    return 0;
}


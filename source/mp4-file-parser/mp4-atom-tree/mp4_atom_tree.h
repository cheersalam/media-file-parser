#pragma once
#include "ByteStreamReaderWriter.h"
#include "mp4_tree_node.h"

namespace mp4atom {
    class Mp4AtomTree
    {
    public:
        Mp4AtomTree();
        ~Mp4AtomTree();

        int CreateAtomTree(std::string filePath);
        int CreateNewMp4File(std::string filePath) const;
        int PrintAtomTree() const;
        int FreeAtomTree() const;

    private:
        ByteStreamReaderWriter *mp4FileReader_;
        int AddSiblingAtom(uint32_t atomType, uint32_t size, char *payload, Mp4TreeNode **sibling);
        Mp4TreeNode* CreateAtomNode(uint32_t atom_type, uint32_t atom_size, char* payload) const;
        Mp4TreeNode * ProcessNode(Mp4TreeNode* node, Mp4TreeNode *parent) const;
        static Mp4TreeNode* FindParentInTree(Mp4TreeNode* parent);
        static int64_t GetChildrenSize(Mp4TreeNode* node);
        int OpenFileForReading(std::string filePath);
        Mp4TreeNode * GetNextAtomNode() const;
        int AddSibling();
        
        static int writeAtoms(Mp4TreeNode* node, ByteStreamReaderWriter *fileWriter);
        static int WalkAtomTree(Mp4TreeNode* node);
        int FreeAllAtoms(Mp4TreeNode* node) const;
        int PrintAtom(Mp4TreeNode* node);
        int printFirstChild(Mp4TreeNode * parent) const;
        int printFirstChild(Mp4TreeNode* parent);
        int PrintAllChildren(Mp4TreeNode * node);
        int PrintAllChildren(Mp4TreeNode* node) const;
        Mp4TreeNode *head;
    };

} //namespace mp4atom

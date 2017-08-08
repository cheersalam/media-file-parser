#include <string>
#include <fstream>
#include "mp4_atom_tree.h"
#include <iostream>
#include "utility.h"
#include "../mp4-atoms/inc/mp4_atom.h"
#include "../mp4-atoms/inc/mp4_atom_factory.h"

namespace mp4atom {
    Mp4AtomTree::Mp4AtomTree()
    {
        head = CreateAtomNode(ATOM_TYPE_DUMM, 0, nullptr);
    }

    Mp4AtomTree::~Mp4AtomTree()
    {
    }

    int Mp4AtomTree::OpenFileForReading(std::string filePath)
    {
        mp4FileReader_ = new ByteStreamReaderWriter();
        return mp4FileReader_->Open(filePath, Mode::READ);
    }

    Mp4TreeNode *Mp4AtomTree::CreateAtomNode(uint32_t atom_type, uint32_t atom_size, char *payload) const
    {
        Mp4TreeNode *node = nullptr;
        Mp4Atom *atom = Mp4AtomFactory::CreateAtom(atom_type, atom_size, payload);
        if (atom != nullptr)
        {
            node = new Mp4TreeNode(atom);
        }
        return node;
    }

    Mp4TreeNode * Mp4AtomTree::GetNextAtomNode() const
    {
        Mp4TreeNode *node = nullptr;
        char header[8] = {0};
        if (mp4FileReader_->GetNextXByteToChar(header, 8) == 0) {
            uint32_t atom_size = 0;
            uint32_t atom_type = 0;
            mp4FileReader_->Convert4ByteToUint(reinterpret_cast<unsigned char *>(&header[0]), &atom_size);
            mp4FileReader_->Convert4ByteToUint(reinterpret_cast<unsigned char *>(&header[4]), &atom_type);
            
            std::cout << reinterpret_cast<unsigned char *>(&atom_type) << std::endl;
            std::cout << atom_size << std::endl;
            node = CreateAtomNode(atom_type, atom_size, nullptr);
            node->mp4Atom->SetHeader(header);
        }
        return node;
    }

    int Mp4AtomTree::CreateAtomTree(std::string filePath)
    {
        Mp4TreeNode *node = nullptr;
        auto res = 0;
        res = OpenFileForReading(filePath);
        if (res == 0)
        {
            head->firstChild = ProcessNode(GetNextAtomNode(), head);
        }
        return res;
    }

    Mp4TreeNode *Mp4AtomTree::ProcessNode(Mp4TreeNode *node, Mp4TreeNode *parent) const
    {
        Mp4TreeNode *newNode = nullptr;
        Mp4TreeNode *actualParent = nullptr;
        if (node == nullptr)
        {
            return nullptr;
        }
        uint32_t atom_size = node->mp4Atom->GetSize();
        if (node->mp4Atom->CanHaveChildren())
        {
            //how do we know it has 
            newNode = GetNextAtomNode();
            node->firstChild = newNode;// ProcessNode(newNode, node);
            ProcessNode(newNode, node);
        }
        else
        {
            uint32_t payload_size = atom_size - 8;
            auto payload = utility::allocateMemory(payload_size);
            if (payload != nullptr) {
                mp4FileReader_->GetNextXByteToChar(payload, payload_size);
                node->mp4Atom->SetPayload(payload, payload_size);
                node->parent = parent;

                newNode = GetNextAtomNode();

                //how do we know it has siblings?
                if (newNode != nullptr) {
                    actualParent = FindParentInTree(parent);
                    if (actualParent != nullptr)
                    {
                        parent = actualParent;
                    }
                    node->nextSibling = newNode;//ProcessNode(newNode, parent);
                    newNode->parent = node->parent;
                    ProcessNode(newNode, parent);
                }
            }
        }
        return node;
    }

    Mp4TreeNode *Mp4AtomTree::FindParentInTree(Mp4TreeNode *parent)
    {
        while (parent != nullptr)
        {
            if ( parent->mp4Atom->GetSize() > GetChildrenSize(parent) + 8) {
                return parent;
            }
            parent = parent->parent;
        }
        return parent;
    }

    int64_t Mp4AtomTree::GetChildrenSize(Mp4TreeNode *parent)
    {
        int64_t size = 0;
        Mp4TreeNode *child = parent->firstChild;
        while (child != nullptr)
        {
            size = size + child->mp4Atom->GetSize();
            child = child->nextSibling;
        }
        return size;
    }

    int Mp4AtomTree::FreeAtomTree() const
    {
        FreeAllAtoms(head);
        return 0;
    }

    int Mp4AtomTree::PrintAtomTree() const
    {
        WalkAtomTree(head);
        return 0;
    }

    int Mp4AtomTree::CreateNewMp4File(std::string filePath) const
    {
        ByteStreamReaderWriter *fileWriter_ = new ByteStreamReaderWriter();
        if (fileWriter_->Open(filePath, Mode::WRITE) == 0)
        {
            writeAtoms(head->firstChild, fileWriter_);
        }
        fileWriter_->Close();
        return 0;
    }

    int Mp4AtomTree::writeAtoms(Mp4TreeNode *node, ByteStreamReaderWriter *fileWriter)
    {
        if (node != nullptr)
        {
            fileWriter->Write(node->mp4Atom->GetHeader(), 8);
            if (!node->mp4Atom->CanHaveChildren())
            {
                fileWriter->Write(node->mp4Atom->GetPayload(), node->mp4Atom->GetPayloadSize());
            }
            writeAtoms(node->firstChild, fileWriter);
            writeAtoms(node->nextSibling, fileWriter);
        }
        return 0;
    }

    int Mp4AtomTree::WalkAtomTree(Mp4TreeNode *node)
    {
        if (node != nullptr)
        {
            node->mp4Atom->PrintAtom();
            WalkAtomTree(node->firstChild);
            WalkAtomTree(node->nextSibling);
        }
        return 0;
    }

    int Mp4AtomTree::FreeAllAtoms(Mp4TreeNode *node) const
    {
        if (node != nullptr)
        {
            FreeAllAtoms(node->firstChild);
            FreeAllAtoms(node->nextSibling);
            delete(node);
        }
        return 0;
    }


    int Mp4AtomTree::PrintAtom(Mp4TreeNode *node)
    {
        if (node != nullptr)
        {
            node->mp4Atom->PrintAtom();
        }
        return 0;
    }

    int Mp4AtomTree::printFirstChild(Mp4TreeNode *parent) const
    {
        Mp4TreeNode *firstChild = parent->firstChild;
        if (firstChild != nullptr)
        {
            firstChild->mp4Atom->PrintAtom();
        }
        return 0;
    }

    int Mp4AtomTree::PrintAllChildren(Mp4TreeNode *node) 
    {
        if (node != nullptr)
        {
            node->mp4Atom->PrintAtom();
        }
        return 0;
    }


    int Mp4AtomTree::AddSiblingAtom(uint32_t atom_type, uint32_t atom_size, char *payload, Mp4TreeNode **sibling)
    {
        Mp4TreeNode *node = CreateAtomNode(atom_type, atom_size, payload);        
        if (head == nullptr) {
            head = node;
        }
        else {
            (*sibling)->nextSibling = node;
        }
        *sibling = node;
        return 0;
    }
} //namespace mp4atom

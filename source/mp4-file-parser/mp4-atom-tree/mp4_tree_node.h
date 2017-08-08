#pragma once
#include "../mp4-atoms/inc/mp4_atom.h"

namespace mp4atom {
    class Mp4TreeNode
    {
    public:

        Mp4Atom *mp4Atom;
        Mp4TreeNode();
        Mp4TreeNode(Mp4Atom *atom);
        Mp4TreeNode(Mp4Atom *atom, Mp4TreeNode *parent, Mp4TreeNode *child, Mp4TreeNode *sibling);
        ~Mp4TreeNode();

        void preorder();
        void postorder();
        Mp4TreeNode *parent;
        Mp4TreeNode *firstChild;
        Mp4TreeNode *nextSibling;
    };
} //namespace mp4atom


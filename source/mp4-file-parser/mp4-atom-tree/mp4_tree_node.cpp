#include "mp4_tree_node.h"
#include <cstddef>
#include "../mp4-atoms/inc/mp4_atom.h"

namespace mp4atom {
    Mp4TreeNode::Mp4TreeNode()
        : mp4Atom(NULL)
        , parent(NULL)
        , firstChild(NULL)
        , nextSibling(NULL)
    {
    }

    Mp4TreeNode::Mp4TreeNode(Mp4Atom * atom)
        : mp4Atom(atom)
        , parent(NULL)
        , firstChild(NULL)
        , nextSibling(NULL)
    {
    }

    Mp4TreeNode::Mp4TreeNode(Mp4Atom * atom, Mp4TreeNode * atomParent, Mp4TreeNode * child, Mp4TreeNode * sibling)
        : mp4Atom(atom)
        , parent(atomParent)
        , firstChild(child)
        , nextSibling(sibling)
    {
    }

    Mp4TreeNode::~Mp4TreeNode()
    {
        if (mp4Atom) {
            delete(mp4Atom);
            mp4Atom = NULL;
        }

        if (parent) {
            delete(parent);
            parent = NULL;
        }

        if (firstChild) {
            delete(firstChild);
            firstChild = NULL;
        }

        if (nextSibling) {
            delete(nextSibling);
            nextSibling = NULL;
        }
    }

    void Mp4TreeNode::preorder()
    {
        if (firstChild != NULL) {
            firstChild->preorder();
        }
        if (nextSibling != NULL) {
            nextSibling->preorder();
        }
    }

    void Mp4TreeNode::postorder()
    {
        
        if (firstChild != NULL) {
            firstChild->postorder();
        }
        if (nextSibling != NULL) {
            nextSibling->postorder();
        }
    }

} //namespace mp4atom


#ifndef SEARCHTREE_HPP_INCLUDED
#define SEARCHTREE_HPP_INCLUDED

#include <string>

namespace searchTree {

    typedef struct treeNode {
        std::string text;
        int id;
        bool alive;
        struct treeNode *left, *right;
    }TreeNode;

    TreeNode* insert(TreeNode *root, std::string text, int id, bool alive);

    void printTree(TreeNode* root);
    
}

#endif // SEARCHTREE_HPP_INCLUDED

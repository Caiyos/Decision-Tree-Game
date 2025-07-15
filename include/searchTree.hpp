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

    // Node* remove(Node *root, int key);

    // int search(Node *root, int key);

    void printTree(TreeNode* root);
    
}

#endif // SEARCHTREE_HPP_INCLUDED

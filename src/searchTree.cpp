#include <iostream>

#include "searchTree.hpp"

namespace searchTree {

    TreeNode* insert(TreeNode *root, std::string text, int id, bool alive)
    {
        if(root == nullptr)
        {
            TreeNode *newNode = new TreeNode;
            newNode->text = text;
            newNode->id = id;
            newNode->alive = alive;
            newNode->left = nullptr;
            newNode->right = nullptr;

            return newNode;
        }
        else
        {
            if(id < root->id)
            {
                root->left = insert(root->left, std::string(text), id, alive);
            }
            if(id > root->id)
            {
                root->right = insert(root->right, std::string(text), id, alive);
            }

            return root;
        }

    }
    
    void printTree(TreeNode* root)
    {
        if(root != nullptr)
        {
            printTree(root->left);
            std::cout << root->id << " - " << root->text << " - " << (root->alive ? "Vivo" : "Morto") << std::endl;
            printTree(root->right);
        }
    }
}
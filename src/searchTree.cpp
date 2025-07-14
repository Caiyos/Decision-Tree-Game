#include <iostream>

#include "searchTree.hpp"

namespace searchTree {

    Node* insert(Node *root, int info)
    {
        if(root == nullptr)
        {
            Node *newNode = new Node;
            newNode->info = info;
            newNode->left = nullptr;
            newNode->right = nullptr;

            return newNode;
        }
        else
        {
            if(info < root->info)
            {
                root->left = insert(root->left, info);
            }
            if(info > root->info)
            {
                root->right = insert(root->right, info);
            }

            return root;
        }

    }

    Node* remove(Node *root, int key)
    {
        Node *temp;
        if (root == nullptr)
        {
            std::cout << "Valor nao encontrado" << std::endl;
            return nullptr;
        }
        else if (root->info == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            // remover o nó folha
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)
            // remover o nó com apenas filho direito
            {
                temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            // remover o nó com apenas filho esquerdo
            {
                temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                // Encontrar o maior da subárvore left
                temp = root->left;
                while (temp->right != nullptr)
                    temp = temp->right;

                root->info = temp->info; // Substituir pelo maior info
                root->left = remove(root->left, temp->info); // Remover o maior info
                return root;
            }
        }
        else if (key < root->info)
        {
            root->left = remove(root->left, key);
            return root;
        }
        else
        {
            root->right = remove(root->right, key);
            return root;
        }
    }

    int search(Node *root, int key)
    {
        if(root == nullptr)
        {
            return -1;
        }
        else if(root->info == key)
        {
            return root->info;
        }
        else if(key < root->info)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }

    void printTree(Node* root)
    {
        if(root != nullptr)
        {
            printTree(root->left);
            std::cout << root->info << std::endl;
            printTree(root->right);
        }
    }
}
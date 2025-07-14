#ifndef SEARCHTREE_HPP_INCLUDED
#define SEARCHTREE_HPP_INCLUDED

namespace searchTree {

    typedef struct node {
        int info;
        struct node *left, *right;
    }Node;

    Node* insert(Node *root, int info);

    Node* remove(Node *root, int key);

    int search(Node *root, int key);

    void printTree(Node* root);
    
}

#endif // SEARCHTREE_HPP_INCLUDED

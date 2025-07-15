#ifndef SIMPLELIST_HPP_INCLUDED
#define SIMPLELIST_HPP_INCLUDED

#include <string>

namespace simpleList {

    typedef struct listNode{
        std::string text;
        int id;
        bool alive;
        struct listNode *next;
    }ListNode;

    // void insertNodeStart(Node **list, int num);

    void insertEnd(ListNode **list, int id, std::string text, bool alive);

    // void insertNodeMiddle(Node **list, int num, int prev);

    // void insertInOrder(Node **list, int num);

    // Node* removeElement(Node **list, int num);

    // Node* search(Node **list, int num);

    void printList(ListNode *node);

    void freeList(listNode* head);
    
}

#endif // SIMPLELIST_HPP_INCLUDED

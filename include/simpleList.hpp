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

    void insertEnd(ListNode **list, int id, std::string text, bool alive);

    void printList(ListNode *node);

    void freeList(listNode* head);
    
}

#endif // SIMPLELIST_HPP_INCLUDED

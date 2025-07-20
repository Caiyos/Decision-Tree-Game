#include <iostream>

#include "simpleList.hpp"

namespace simpleList {
    
    void insertEnd(ListNode **list, int id, std::string text, bool alive)
    {
        ListNode *aux, *newNode = new ListNode;
    
        if(newNode == nullptr)
        {
            std::cout << "erro de alocação" << std::endl;
            return;
        }
    
        newNode->id = id;
        newNode->text = text;
        newNode->alive = alive;
        newNode->next = nullptr;
        
        if(*list == nullptr)
        {
            *list = newNode;
        }
        else
        {
            aux = *list;
            while(aux->next != nullptr)
            {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    
    }
    
    
    void printList(ListNode *node)
    {
        std::cout << "lista:" << std::endl;
    
        while(node != nullptr)
        {
            std::cout << node->id << " - " << node->text << " - " << (node->alive ? "Vivo" : "Morto") << std::endl;
            node = node->next;
        }
    }

    void freeList(listNode* head) 
    {

        if (head == nullptr) return;

        while (head != nullptr) 
        {
            listNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

}

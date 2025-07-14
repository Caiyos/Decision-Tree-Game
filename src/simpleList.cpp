#include <iostream>

#include "simpleList.hpp"

namespace simpleList {

    /*
    void insertNodeStart(Node **list, int num)
    {
        Node *newNode = new Node;
    
        if(newNode == nullptr)
        {
            std::cout << "erro de alocação" << std::endl;
            return;
        }
    
        newNode->info = num;
        newNode->next = *list;
        *list = newNode;
    
    }
    */
    
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

    /*
    void insertNodeMiddle(Node **list, int num, int prev)
    {
        Node *aux, *newNode = new Node;
    
        if(newNode == nullptr)
        {
            std::cout << "erro de alocação" << std::endl;
            return;
        }
    
        newNode->info = num;
    
        if(*list == nullptr)
        {
            newNode->next = nullptr;
            *list = newNode;
        }
        else
        {
            aux = *list;
            while(aux->info != prev && aux->next != nullptr)
            {
                aux = aux->next;
            }
    
            newNode->next = aux->next;
            aux->next = newNode;
    
        }
    
    }
    */
    
    /*
    void insertInOrder(Node **list, int num)
    {
        Node *aux, *newNode = new Node;
    
        if(newNode == nullptr)
        {
            std::cout << "erro de alocação" << std::endl;
            return;
        }
    
        newNode->info = num;
    
        if(*list == nullptr)
        {
            newNode->next = nullptr;
            *list = newNode;
        }
        else if(newNode->info < (*list)->info)
        {
            newNode->next = *list;
            *list = newNode;
        }
        else
        {
            aux = *list; 
    
            while(aux->next != nullptr && newNode->info > aux->next->info)
            {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
    
    }
    */
    
    /*
    Node* removeElement(Node **list, int num)
    {
        Node *aux, *remove = nullptr;
    
        if(*list != nullptr)
        {
            std::cout << "lista vazia" << std::endl;
        }
    
        if((*list)->info == num)
        {
            remove = *list;
            *list = remove->next;
        }
        else
        {
            aux = *list;
            while(aux->next != nullptr && aux->next->info != num)
            {
                aux = aux->next;
            }
            if(aux->next != nullptr)
            {
                remove = aux->next;
                aux->next = remove->next; 
            }
        }
    
        return remove;
    }
    */
    
    /*
    Node* search(Node **list, int num)
    {
        Node *node, *aux = nullptr;
    
        aux = *list;
        while(aux != nullptr && aux->info != num)
        {
            aux = aux->next;
        }
    
        if(aux != nullptr)
        {
            node = aux;
        }
    
        return node;
    }
    */
    
    
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

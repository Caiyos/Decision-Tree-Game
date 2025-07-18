#include <iostream>
#include <string.h>
#include <conio.h>

#include "pairList.hpp"

namespace pairList {
    
    /*
    PlayerListNode* insertEnd(PlayerListNode*& head, const PlayerData& data) {

        PlayerListNode* newNode = new PlayerListNode(data);
        std::cout << "DEBUG: pairList::insertEnd chamada. newNode: " << newNode << std::endl;
        _getch();

        if(newNode == nullptr) {
            std::cout << "erro de alocação" << std::endl;
            return nullptr; 
        }
        
        if(head == nullptr) {
            head = newNode;
        } 
        else {
            PlayerListNode* current = head; 

            while(current->next != nullptr) { 
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        std::cout << "DEBUG: Nodo inserido com sucesso. Retornando newNode." << std::endl;
        _getch();
        return newNode; 
    }
    */

    PlayerListNode* insertSorted(PlayerListNode*& head, const PlayerData& data) 
    {
        PlayerListNode* newNode = new PlayerListNode(data);

        if (!newNode) 
        {
            std::cerr << "erro de alocação\n";
            return nullptr;
        }

        if (head == nullptr) 
        {
            head = newNode;
            return newNode;
        }

        PlayerListNode* current = head;
        // Percorre até encontrar o primeiro nó com menos vitórias que newNode
        while (current && current->data.wins >= data.wins) 
        {
            current = current->next;
        }

        // Caso 1: inserir antes do head
        if (current == head) 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        // Caso 2: chegou ao fim da lista, insere no final
        else if (current == nullptr) 
        {
            PlayerListNode* tail = head;

            while (tail->next) tail = tail->next;

            tail->next = newNode;
            newNode->prev = tail;
        }
        // Caso 3: insere entre current->prev e current
        else {
            PlayerListNode* prevNode = current->prev;

            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = current;
            current->prev = newNode;
        }

        return newNode;
    }
    
    PlayerListNode* findPlayerNode(PlayerListNode* head, const std::string& playerName) 
    {
        PlayerListNode* current = head;
        while (current != nullptr) 
        {
            if (current->data.name == playerName) 
            {
                return current; 
            }

            current = current->next;
        }

        return nullptr; 
    }

    void printList(PlayerListNode *head)
    {
        std::cout << "lista dupla:" << std::endl;
    
        while(head != nullptr)
        {
            std::cout << "Nome: " << head->data.name << " Partidas Jogadas: " << head->data.gamesPlayed 
                        << " Vitórias: " << head->data.wins<< " Derrotas" << head->data.losses <<std::endl;
            head = head->next;
        }
    }

    void freeList(PlayerListNode* head) 
    {
        if (head == nullptr) return;

        while (head != nullptr) 
        {
            PlayerListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }


    int size(PlayerListNode* head)
    {
        PlayerListNode* aux = head;
        int cont = 0;

        while(aux!=nullptr) 
        {
            cont++;

            aux = aux->next;
        }

        return cont;
    }
}

#include <iostream>
#include "pairList.hpp"
#include <string.h>
#include <conio.h>
namespace pairList {
    
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

    PlayerListNode* findPlayerNode(PlayerListNode* head, const std::string& playerName) {
        PlayerListNode* current = head;
        while (current != nullptr) {
            if (current->data.name == playerName) {
                return current; 
            }
            current = current->next;
        }
        return nullptr; 
    }

    int size(PlayerListNode* head){
        PlayerListNode* aux = head;
        int cont = 0;
        while(aux!=nullptr)
            cont++;

        return cont;
        
    }
}

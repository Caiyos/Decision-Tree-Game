#ifndef PAIRLIST_HPP_INCLUDED
#define PAIRLIST_HPP_INCLUDED

#include "PlayerData.hpp"
#include <string.h>

namespace pairList {

    struct PlayerListNode {
    PlayerData data;
    PlayerListNode* next;
    PlayerListNode* prev; 

    PlayerListNode(const PlayerData& pd) : data(pd), next(nullptr), prev(nullptr) {}
    };
    
    PlayerListNode* insertEnd(PlayerListNode*& head, const PlayerData& data); 

    void printList(PlayerListNode *head);

    void freeList(PlayerListNode* head);
    
    PlayerListNode* findPlayerNode(PlayerListNode* head, const std::string& playerName);
    
    int size(PlayerListNode* head);
}

#endif // PAIRLIST_HPP_INCLUDED

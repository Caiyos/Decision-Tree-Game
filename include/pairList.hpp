#ifndef PAIRLIST_HPP_INCLUDED
#define PAIRLIST_HPP_INCLUDED

#include "PlayerData.hpp"
#include <string.h>

namespace pairList {

    struct PlayerListNode {
        PlayerData data;
        PlayerListNode* next;
        PlayerListNode* prev; 

        PlayerListNode(const PlayerData& pd) 
            : data(pd), 
              next(nullptr), 
              prev(nullptr) 
        {}
    };

    /*
    PlayerListNode* insertEnd(PlayerListNode*& head, const PlayerData& data); 
    */

    PlayerListNode* insertSorted(PlayerListNode*& head, const PlayerData& data); 

    PlayerListNode* findPlayerNode(PlayerListNode* head, const std::string& playerName);

    void printList(PlayerListNode *head);

    void freeList(PlayerListNode* head);
    
    int size(PlayerListNode* head);
}

#endif // PAIRLIST_HPP_INCLUDED

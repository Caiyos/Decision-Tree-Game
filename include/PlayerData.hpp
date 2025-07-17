#ifndef PLAYER_DATA_HPP
#define PLAYER_DATA_HPP

#include <string>

struct PlayerData {
    std::string name;
    int gamesPlayed;
    int wins;
    int losses;

    PlayerData(const std::string& n = "", int gp = 0, int w = 0, int l = 0)
        : name(n), gamesPlayed(gp), wins(w), losses(l) {}

    PlayerData(): name(""), gamesPlayed(0), wins(0), losses(0){}
};

#endif 
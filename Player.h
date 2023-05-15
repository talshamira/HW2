//
// Created by user on 13/05/2023.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

//#define DEFAULT_MAX_HP 100
//#define DEFAULT_FORCE 5

#include <iostream>
#include <string>
#include "utilities.h"
using namespace std; //TODO check if can use in header

class Player {

public:
    Player(string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    ~Player() = default;
    Player(const Player&) = default; //TODO check if can be default
    Player & operator=(const Player &) = default; //TODO check if can be default

    //check for const at the end
    void printInfo() const; //maybe needs to be friend
    void levelUp();
    int getLevel() const;
    void buff(int forceToAdd);
    void heal(int hpToAdd);
    void damage(int hpToDiminish);
    bool isKnockedOut() const;
    void addCoins(int coinsToAdd);
    bool pay(int coinsToPay);
    int getAttackStrength() const;




private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;


    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
};


#endif //EX2_PLAYER_H

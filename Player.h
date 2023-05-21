//
// Created by user on 13/05/2023.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>
#include <string>
#include "utilities.h"


class Player {

public:
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;

    //Constractor. get from the user name, maxHP and force or just name.
    //The default values: maxHP - 100, force - 5;
    Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    //default destractor, copy constractor and operator=.
    ~Player() = default;
    Player(const Player&) = default;
    Player & operator=(const Player &) = default;

    //Prints players details: name, level, force, HP and coins.
    void printInfo() const;

    //Level up the players level.
    void levelUp();

    //Returns the players level.
    int getLevel() const;

    //Gets points to add to force and adds them.
    void buff(int forceToAdd);

    //get points to add to hp and adds them. make sure the current hp isnt higher then maxHP.
    void heal(int hpToAdd);

    //Gets hp to diminish from player and diminishes it. If the result is negative, change to 0.
    void damage(int hpToDiminish);

    //Returns true if hp is 0 and false otherwise.
    bool isKnockedOut() const;

    //Gets amount of coins to add to the player and adds them.
    void addCoins(int coinsToAdd);

    //Gets amount pf coins that the player needs to play (diminish from his coins).
    //Returns true if the player has coins to pay and false otherwise.
    bool pay(int coinsToPay);

    //Returns the attack strength. attack strength = force + level
    int getAttackStrength() const;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};


#endif //EX2_PLAYER_H

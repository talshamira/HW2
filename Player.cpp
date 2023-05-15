//
// Created by user on 13/05/2023.
//

#include "Player.h"
using namespace std;

Player::Player(string name, int maxHP, int force) :
    m_name(name),
    m_maxHP(maxHP),
    m_force(force),
    m_level(1),
    m_coins(0),
    m_HP(maxHP) {
    if(maxHP <= 0)
    {
        this->m_maxHP = DEFAULT_MAX_HP;
    }
    if(force < 0)
    {
        this->m_force = DEFAULT_FORCE;
    }
}

void Player::printInfo() const {
    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp() {
    ++this->m_level;
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int forceToAdd) {
    this->m_force += forceToAdd;
}

void Player::heal(int hpToAdd) {
    if(hpToAdd > 0)
    {
        if(this->m_HP + hpToAdd <= this->m_maxHP)
        {
            this->m_HP += hpToAdd;
        }
    }
}

void Player::damage(int hpToDiminish) {
    if(hpToDiminish > 0)
    {
        if(hpToDiminish >= this->m_HP)
        {
            this->m_HP = 0;
        }
        else
        {
            this->m_HP -= hpToDiminish;
        }
    }
}

bool Player::isKnockedOut() const {
    if(this->m_HP == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) {
    this->m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay <= this->m_coins)
    {
        this->m_coins -= coinsToPay;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return (this->m_level + this->m_force);
}
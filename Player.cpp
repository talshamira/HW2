//
// Created by user on 13/05/2023.
//

#include "Player.h"
using namespace std;


Player::Player(string name, int maxHP, int force) :
    m_name(name),
    m_level(1),
    m_force(force),
    m_maxHP(maxHP),
    m_HP(maxHP),
    m_coins(0)
{
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
    if(this->m_level < MAX_LEVEL)
    {
        this->m_level++;
    }
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int forceToAdd) {
    if(forceToAdd > 0)
    {
        this->m_force += forceToAdd;
    }
}

void Player::heal(int hpToAdd) {
    if(hpToAdd > 0)
    {
        if(this->m_HP + hpToAdd <= this->m_maxHP)
        {
            this->m_HP += hpToAdd;
        }
        else
        {
            this->m_HP = this->m_maxHP;
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
    if(this->m_HP <= 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) {
    if(coinsToAdd > 0)
    {
        this->m_coins += coinsToAdd;
    }  
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay > 0)
    {
        if(coinsToPay <= this->m_coins)
        {
            this->m_coins -= coinsToPay;
            return true;
        }
        return false;
    }
    return true;
}

int Player::getAttackStrength() const {
    return (this->m_level + this->m_force);
}
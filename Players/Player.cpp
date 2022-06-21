//
// Created by eyalb on 09/06/2022.
//
#include <string>
#include "Player.h"
#include "../Exception.h"
#include "../utilities.h"

Player::Player(const string &playerName,const string& playerType) {


    this->m_name = playerName;
    this->m_type = playerType;
    this->m_level = 1;
    this->m_force = 5;
    this->m_maxHP = 100;
    this->m_HP = m_maxHP;
    this->m_coins = 10;
}

Player::Player(const std::string &playerName,const string &playerType, int maximumHp) {

    if (maximumHp <= 0) {
        throw NonPositive(true);
    }
    this->m_name = playerName;
    this->m_type = playerType;
    this->m_level = 1;
    this->m_force = 5;
    this->m_maxHP = maximumHp;
    this->m_HP = maximumHp;
    this->m_coins = 10;
}


Player::Player(const std::string &playerName,const string &playerType,int maximumHp, int initialForce) {

    if (maximumHp <= 0) {
        throw NonPositive(true);
    }
    if (initialForce <= 0) {
        throw NonPositive(true);
    }
    m_name = playerName;
    m_type = playerType;
    m_level = 1;
    m_coins = 10;
    m_maxHP = maximumHp;
    m_HP = maximumHp;
    m_force = initialForce;
}

void Player::levelUp() {
    if (m_level < 10)
        m_level++;
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int force) {
    if (force < 0) {
        throw NonPositive(false);
    }
    this->m_force += force;
}


void Player::nerf(int force) {
    if (force < 0) {
        throw NonPositive(false);
    }
    if (m_force > force)
        this->m_force -= force;
    else this->m_force = 0;
}

void Player::heal(int hpAddition) {
    if (hpAddition < 0) {
        throw NonPositive(false);
    }
    if (this->m_HP + hpAddition >= this->m_maxHP) {
        this->m_HP = this->m_maxHP;
    } else
        this->m_HP += hpAddition;
}

void Player::damage(int hpReducing) {
    if (hpReducing < 0) {
        throw NonPositive(false);
    }
    if (this->m_HP - hpReducing <= 0) {
        this->m_HP = 0;
    } else
        this->m_HP -= hpReducing;
}

bool Player::isKnockedOut() const {
    return m_HP == 0;
}

void Player::addCoins(int coinsAddition) {
    if (coinsAddition < 0) {
        throw NonPositive(false);
    }
    this->m_coins += coinsAddition;
}

bool Player::pay(int payment) {
    if (payment < 0) {
        throw NonPositive(false);
    }
    if (this->m_coins - payment < 0) {
        return false;
    }
    this->m_coins -= payment;
    return true;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}

bool isInEnglish(const std::string &name) {
    for (const char c: name) {
        if ((c > 'z' || c < 'a' )&& (c > 'Z' || c < 'A'))
            return false;
    }
    return true;
}

const std::string &Player::getName() const
{
    return this->m_name;
}

int Player::getCoins() const {
    return this->m_coins;
}

int Player::getHp() const {
    return this->m_HP;
}

int Player::getForce() const {
    return this->m_force;
}

const std::string &Player::getType() const {
    return this->m_type;
}

bool Player::isWin()  const {
    if(this->m_level==10){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& ostream,const Player &player)
{
    printPlayerDetails(ostream,player.getName(),player.getType(),player.getLevel(),
                       player.getForce(),player.getHp(),player.getCoins());
    return ostream;

}


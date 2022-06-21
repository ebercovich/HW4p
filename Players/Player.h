//
// Created by eyalb on 09/06/2022.
//
#ifndef HW4_PLAYER_H
#define HW4_PLAYER_H

#include <string>


class Player {
public:
    explicit Player(const std::string &,const std::string&);

    Player(const std::string & ,const std::string &,int);

    Player(const std::string &,const std::string &,int, int);

    Player(const Player &) = default;

    virtual ~Player() = default;

    Player &operator=(const Player &) = delete;

    void levelUp();

    int getLevel() const;
    int getForce() const;
    int getHp() const;
    int getCoins() const;

    bool isWin() const;

    void buff(int);

    void nerf(int);

    virtual void heal(int);

    void damage(int);

    bool isKnockedOut() const;

    virtual void addCoins(int);

    bool pay(int);

    virtual int getAttackStrength() const;

    const std::string &getName() const;

    const std::string &getType() const;

    friend std::ostream& operator<<(std::ostream& ostream,const Player& player);



protected:


    std::string m_name;
    std::string m_type;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};

bool isInEnglish(const std::string &);

#endif //HW4_PLAYER_H

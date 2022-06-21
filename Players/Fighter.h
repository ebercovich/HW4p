//
// Created by eyalb on 10/06/2022.
//

#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include <string>
#include "Player.h"

class Fighter : public Player {

public:
    explicit Fighter(const std::string &);

    Fighter(const std::string &, int);

    Fighter(const std::string &, int, int);

    Fighter(const Fighter &) = default;

    Fighter operator=(const Fighter &) = delete;

    ~Fighter() override = default;

    int getAttackStrength() const override;


};

#endif //HW4_FIGHTER_H

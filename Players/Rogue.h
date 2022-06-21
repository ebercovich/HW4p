//
// Created by eyalb on 10/06/2022.
//

#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H

#include <string>
#include "Player.h"

class Rogue : public Player {
public:
    explicit Rogue(const std::string &);

    Rogue(const std::string &, int);

    Rogue(const std::string &, int, int);

    Rogue(const Rogue &) = default;

    ~Rogue() override = default;

    Rogue &operator=(const Rogue &) = delete;

    void addCoins(int) override;

};



#endif //HW4_ROGUE_H

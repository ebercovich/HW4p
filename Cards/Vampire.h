//
// Created by Nir on 6/12/2022.
//

#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle {

public:
    Vampire();

    Vampire(const Vampire &) = default;

    ~Vampire() override = default;

    Vampire &operator=(const Vampire &) = delete;

    bool fight(Player &) override;
};


#endif //HW4_VAMPIRE_H

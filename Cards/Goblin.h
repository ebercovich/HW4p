//
// Created by Nir on 6/12/2022.
//

#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle {
public:
    Goblin();

    Goblin(const Goblin &) = default;

    ~Goblin() override = default;

    Goblin &operator=(const Goblin &) = delete;

};

#endif //HW4_GOBLIN_H


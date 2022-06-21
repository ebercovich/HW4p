//
// Created by Nir on 6/12/2022.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H

#include "Battle.h"


class Dragon : public Battle {
public:
    Dragon();

    Dragon(const Dragon &) = default;

    ~Dragon() override = default;

    Dragon &operator=(const Dragon &) = delete;
};

#endif //HW4_DRAGON_H

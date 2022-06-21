//
// Created by eyalb on 10/06/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H

#include <string>
#include "Player.h"

class Wizard : public Player {
public:
    explicit Wizard(const std::string &);

    Wizard(const std::string &, int);

    Wizard(const std::string &, int, int);

    Wizard(const Wizard &) = default;

    ~Wizard() override = default;

    Wizard &operator=(const Wizard &) = delete;

    void heal(int) override;

};

#endif //HW4_WIZARD_H

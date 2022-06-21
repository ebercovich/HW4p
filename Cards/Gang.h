//
// Created by eyalb on 19/06/2022.
//

#ifndef HW4_GANG_H
#define HW4_GANG_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Battle.h"
#include "../Players/Player.h"

class Gang : public Card {
public:
    Gang();

    Gang(Gang &) = default;

    ~Gang() override = default;

    Gang &operator=(Gang &) = delete;

    void pushEnemy(const string &enemy, int lineInfile);

    bool fight(Player &);

    void lose(Player &, std::vector<std::unique_ptr<Battle>>::iterator);

    void applyEncounter(Player &player) override;

    void printInfo(std::ostream &os) const override;

private:
    std::vector<std::unique_ptr<Battle>> m_enemies;
};


#endif //HW4_GANG_H

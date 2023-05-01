#pragma once

#include "include/creature/creature.h"

class Player : public Creature
{
public:
    int money = 1000;

    Player();

    void print();
};


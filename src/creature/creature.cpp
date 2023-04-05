#include "include/creature/creature.h"

Creature::Creature(int level, int power, int dexterity,
                   int endurance, int intelligence, int spirit, QString name)
    : level{level}, power{power}, dexterity{dexterity}, endurance{endurance},
    intelligence{intelligence}, spirit{spirit}, name{name}
{

}

Creature::Creature()
: level{0}, power{0}, dexterity{0}, endurance{0},
    intelligence{0}, spirit{0}, name{"None"}
{}

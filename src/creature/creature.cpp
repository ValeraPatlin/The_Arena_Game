#include "include/creature/creature.h"

Creature::Creature(int level, int power, int dexterity,
                   int endurance, int intelligence,
                   int spirit, QString sex, QString name)
    : level{level}, power{power}, dexterity{dexterity}, endurance{endurance},
    intelligence{intelligence}, spirit{spirit}, sex{sex}, name{name}
{

}

Creature::Creature()
    : Creature(0, 0, 0, 0, 0, 0, "Мужчина", "None")
{}



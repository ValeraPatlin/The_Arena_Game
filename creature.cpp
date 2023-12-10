#include "creature.h"

Creature::Creature(int level, int power, int dexterity,
                   int endurance, int intelligence,
                   int spirit, QString species, QString sex, QString name)
    : level{level}, power{power}, dexterity{dexterity}, endurance{endurance},
    intelligence{intelligence}, spirit{spirit}, species{species}, sex{sex}, name{name}
{
    //portrait = new QPixmap();
}

Creature::Creature()
    : Creature(0, 0, 0, 0, 0, 0, "Человек", "Мужчина", "None")
{}

Creature::~Creature()
{
    //delete portrait;
}

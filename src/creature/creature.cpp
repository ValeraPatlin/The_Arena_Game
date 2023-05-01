#include "include/creature/creature.h"



Creature::Creature(int level, int power, int dexterity,
                   int endurance, int intelligence,
                   int spirit, QString sex, QString name)
    : power{power}, dexterity{dexterity}, endurance{endurance}, intelligence{intelligence},
    spirit{spirit}, level{level}, sex{sex}, name{name}
{
    //portrait = new QPixmap();
}

Creature::Creature()
    : Creature(0, 0, 0, 0, 0, 0, "Мужчина", "None")
{}

Creature::~Creature()
{
    //delete portrait;
}

//-----------


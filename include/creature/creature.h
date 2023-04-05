#pragma once

#include <QString>

class Creature
{
    public:
    //параметры персонажа
    /*
     * parameters
     *
     * power        - сила
     * dexterity    - ловкость
     * endurance    - выносливость
     * intelligence - интелект
     * spirit       - дух
     *
     */

    int power;
    int dexterity;
    int endurance;
    int intelligence;
    int spirit;

    int level;

    QString name;


    Creature(int level, int power, int dexterity,
             int endurance, int intelligence, int spirit, QString name);

    Creature();
};



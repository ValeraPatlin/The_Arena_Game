#ifndef CREATURE_H
#define CREATURE_H

#include <QString>
#include <QPixmap>

class Creature
{
public:
    int level;

    int power;
    int dexterity;
    int endurance;
    int intelligence;
    int spirit;

    //---------------------------
    //расчитываемые параметры
    int hp = 50;
    int mana = 10;
    int stamina = 20;

        // защита
    QString armor = "нет";          // броня
    int physical_protection = 0;    // физ. защита
    int magical_protection = 0;     // маг. защита
    int parrying = 0;               // парирование
    int evasion = 0;                // уклонение

        // атака
    int physical_attack = 1;    // физ. атака
    int magical_attack = 0;     // маг. атака

        // точность
    int close_combat = 1;  // ближний бой
    int ranged_combat = 1;  // дальний бой

    //------------------------------

    QString sex;
    QString name;

    QString species;  //раса

    QPixmap portrait;   //портрет

    //---------

    Creature(int level, int power, int dexterity,
             int endurance, int intelligence, int spirit,
             QString species, QString sex, QString name);

    Creature();

    virtual ~Creature();

    //-----------------------------------------------------------------------

    // функция расчета параметров
    virtual void calculation_parameters() = 0;

    //функция нанесения урона
    //функция получения урона
    //может быть функция применение способностей
};

#endif // CREATURE_H

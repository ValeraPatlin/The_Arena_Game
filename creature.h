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
    double chance_hit = 0.5; // шанс критического удара
    int critical_hit = 2;    // критический удар

        // точность
    int close_combat = 1;       // ближний бой
    int ranged_combat = 1;      // дальний бой
    int accuracy_magical_hit = 0;    // маг. атака

        // пробивание брони
    double armor_piercing_close = 0.2; // ближний бой
    double armor_piercing_ranged = 0;  // дальний бой
    double armor_piercing_magical = 0; // маг. атака

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

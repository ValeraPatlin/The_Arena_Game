#pragma once

#include <QGuiApplication>
#include <QString>
#include <QPixmap>


class Creature
{
    public:
    //параметры персонажа основные
    /*
     * parameters
     *
     * power        - сила
     * dexterity    - ловкость
     * endurance    - выносливость
     * intelligence - интелект
     * spirit       - дух
     *
     *---------------------
     * физ. защита  physical protection
     * маг. защита  magical protection
     *
     * физ. атака   physical attack
     * маг. атака   magic attack
     *
     * ---------------------
     *
     * hp_bar           - жизни         (50)
     * mana_bar         - мана          (10)
     * endurance_bar    - выносливость  (20)
     *
     * жизни
     * мана
     * стамина (энергия для удара)  - stamina
     *
     */
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

    int physical_protection = 0;
    int magical_protection = 0;

    int physical_attack = 0;
    int magical_attack = 0;

    //------------------------------

    QString sex;
    QString name;

    QString species;  //раса

    QPixmap portrait;   //портрет

//---------

    Creature(int level, int power, int dexterity,
             int endurance, int intelligence, int spirit,
             QString sex, QString name);

    Creature();

    virtual ~Creature();

    //-----------------------------------------------------------------------

    //функция нанесения урона
    //функция получения урона
    //может быть функция применение способностей

};



#pragma once

#include <QGuiApplication>
#include <QString>
#include <QPixmap>


#include <QImage>


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

    QString sex;
    QString name;

    QPixmap portrait;

    //QImage portrait;


    Creature(int level, int power, int dexterity,
             int endurance, int intelligence, int spirit, QString sex, QString name);

    Creature();

    virtual ~Creature();



};



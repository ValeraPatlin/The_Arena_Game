#pragma once

#include <QGuiApplication>
#include <QString>
#include <QPixmap>
#include <QProgressBar>
#include <QGroupBox>
#include <QBoxLayout>
#include <QString>


#include <QImage>


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
     */

    int power;
    int dexterity;
    int endurance;
    int intelligence;
    int spirit;

    int level;

    QString sex;
    QString name;

    QString species;  //раса

    QPixmap portrait;




/*
 * создание виджета для индикаторов

 * hp_bar           - жизни
 * mana_bar         - мана
 * endurance_bar    - выносливость
 *
 * Функция progreess_box() устанавливает индикаторы
 * для основных параметров
 *
 *          // Может всё в отдельный класс???   -----------------------------------------
 *          // надо подумать
 */
    //индикаторы
    QProgressBar* hp_bar;
    QProgressBar* mana_bar;
    QProgressBar* endurance_bar;

    //установка стилей
    void hp_bar_style();
    void mana_bar_style();
    void endurance_bar_stylea();

    QGroupBox *progreess_box();

    QProgressBar* create_prog_bar(QProgressBar* prog_bar, int min, int max);

    //функция расчёта характеристик



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



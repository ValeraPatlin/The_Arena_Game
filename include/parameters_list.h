#pragma once

#include <QLabel>
#include <QBoxLayout>
#include <QGroupBox>
#include <QString>
#include <QFormLayout>

#include "include/creature/player.h"

/*
 * создание виджета для списка параметров
 *
 * Функция parameters_list() принемает класс играка
 * - для первоночального создания персонажа
 * - для увеличения уровня персонажа
 *
 */

class Parameters_list
{
    QLabel* power;
    QLabel* dexterity;
    QLabel* endurance;
    QLabel* intelligence;
    QLabel* spirit;
    QLabel* level;

    QLabel* hp;
    QLabel* mana;
    QLabel* stamina;

    QLabel* physical_protectio;
    QLabel* magical_protection;

    QLabel* physical_attack;
    QLabel* magical_attack;

    /*
     * parameters
     *
     * power        - сила
     * dexterity    - ловкость
     * endurance    - выносливость
     * intelligence - интелект
     * spirit       - дух
     *
     *
     * hp
     * mana
     * stamina
     *
     * physical_protection  - физ. защита
     * magical_protection   - маг. защита
     *
     * physical_attack      - физ. атака
     * magical_attack       - маг. атака
     *
     *
     */


public:
    Parameters_list();

    QGroupBox *param_list(Player &player);

    void create_parameters_list(Player &player);
};



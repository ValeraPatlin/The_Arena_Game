#include "player.h"

#include <QDebug>

Player::Player() : Creature()
{

}

//расчет параметров
/*
     * parameters
     *
     * buffer_power          - сила
     * buffer_dexterity      - ловкость
     * buffer_endurance      - выносливость
     * buffer_intelligence   - интелект
     * buffer_spirit         - дух
     *
     * hp       - жизни     (50)    - изначальные данные
     * mana     - мана      (10)
     * stamina  - стамина   (20)    (энергия для удара)
     *
     *---------------------
     * физ. защита  physical_protection
     * маг. защита  magical_protection
     *
     * физ. атака   physical_attack
     * маг. атака   magical_attack
     *
     * ---------------------
     *
     * сила         +2 к жизни, +1 физ. атака
     * ловкость     +1 физ. защита
     * выносливость +5 стамина, +1 к жизни
     * интелект     +2 мана, +1 маг. атака
     * дух          +5 мана, +1 маг. защита
     *
     *
     */

void Player::calculation_parameters()
{
    // нужен ли этот метод?????????
}

void Player::setting_characteristics(QString path)
{
    // в разработки
}

//


void Player::print()
{
    qDebug() << power << dexterity << endurance << intelligence << spirit << sex << name;
}


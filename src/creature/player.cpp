#include "include/creature/player.h"

#include <QDebug>

Player::Player() : Creature()
{

}

void Player::print()
{
    qDebug() << power << dexterity << endurance << intelligence << spirit;
}

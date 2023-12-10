#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature
{
    int buffer_power{0};
    int buffer_dexterity{0};
    int buffer_endurance{0};
    int buffer_intelligence{0};
    int buffer_spirit{0};

public:
    int money = 1000;

    Player();

    // функция расчета параметров
    void calculation_parameters() override;

    // метод для загрузки персонажа из файла. Метод принимает путь до файла
    void setting_characteristics(QString path);

    void print();
};

#endif // PLAYER_H

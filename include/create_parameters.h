#pragma once

#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>

#include "include/creature/player.h"

/*
 * создание виджетов для параметров персонажа
 * и записи их в класс Player
 *
 * Функция create_parameters принемает количество очков параметров
 * - для первоночального создания персонажа
 * - для увеличения уровня персонажа
 *
 */

extern Player* player;

QFormLayout* create_parameters(int& param_point);
QHBoxLayout* create_spin_box(QLabel* str_param_point,
                             int& param_point, int& param);
void label_param_point(QLabel* str_param_point,
                       QSpinBox* spin_box,
                       int &param_point, int& param);

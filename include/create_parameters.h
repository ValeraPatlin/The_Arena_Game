#pragma once

#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QProgressBar>
#include <QString>

#include "include/creature/player.h"
#include "include/parameters_list.h"

/*
 * создание виджетов для параметров персонажа
 * и записи их в класс Player
 *
 * Функция create_parameters() принемает количество очков параметров
 * и класс играка
 * - для первоночального создания персонажа
 * - для увеличения уровня персонажа
 *
 */

QFormLayout* create_parameters(int& param_point,
                               Player& player,
                               Parameters_list& param_list,
                               bool money = false);

QHBoxLayout* create_spin_box(QLabel* str_param_point,
                             int& param_point, int& param,
                             Player& player,
                             Parameters_list& param_list);

void label_param_point(QLabel* str_param_point,
                       QSpinBox* spin_box,
                       int &param_point, int& param,
                       Player& player,
                       Parameters_list& param_list);



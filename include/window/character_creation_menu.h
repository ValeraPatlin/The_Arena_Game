#pragma once

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QBoxLayout>
#include <QGroupBox>
#include <QFormLayout>

#include "include/window/settings.h"
#include "include/creature/player.h"

extern Player* player;

class Character_creation_menu : public QWidget
{
    Q_OBJECT

    int parameters_point = 10;

    QLabel* str_parameters_point;

    QHBoxLayout* create_spin_box(int& param);

public:
    explicit Character_creation_menu(QWidget *parent = nullptr);

public slots:
    void start_menu_character_creation_slot();

private slots:
    void parameters_player_slot();
};



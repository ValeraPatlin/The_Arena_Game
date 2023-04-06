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

#include "include/window/settings.h"    //???

#include "include/create_parameters.h"
#include "include/widget_info.h"

/*
 * Меню создания персонажа
 * и настроек мира
 */

extern Player* player;

class Character_creation_menu : public QWidget
{
    Q_OBJECT

    int parameters_point = 10;  //количество очков параметров



//player
    QLabel* help;       //для информации
    QLineEdit* player_name;     //имя персонажа
    QLabel* player_portrait;    //портрет персонажа

    //sex
    QRadioButton* men;
    QRadioButton* women;

public:
    explicit Character_creation_menu(QWidget *parent = nullptr);

public slots:
    void start_menu_character_creation_slot();

private slots:
    void start_slot();


    void parameters_player_slot(); //???
};



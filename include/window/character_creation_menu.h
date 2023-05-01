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
#include <QString>
#include <QPixmap>
#include <QProgressBar>
#include <QMenu>
#include <QFileDialog>
#include <QRadioButton>
#include <vector>

#include "include/window/settings.h"    //???


#include "include/parameters_bar.h"
#include "include/parameters_list.h"

/*
 * Меню создания персонажа
 * и настроек мира
 */

//extern Player* player;//----------------------------------------------------

class Character_creation_menu : public QWidget
{
    Q_OBJECT

    Player player;

    Parameters_bar param_bar;
    Parameters_list param_list;


    // изменить возхможно!!
    int total_money = 1000;   //количество денег у персонажа
    //выбрано ли оружие и одежда
    bool weapon_selected = false, clothes_selected = false;



    int parameters_point = 10;  //количество очков параметров
    int index_pixmap = 0;

    QString str_sex;

    std::vector<QPixmap> person_men;
    std::vector<QPixmap> person_women;

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
    void sex_slot();
    void portrait_slot();


    void parameters_player_slot(); //???
};



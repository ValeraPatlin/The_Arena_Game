#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>
#include <QGroupBox>
#include <QString>

#include <QDebug>

#include "include/creature/player.h"


#include "include/create_parameters.h"


//extern Player* player;//---------------------------------------------------------
/*
 * Окно характеристик игрока
 *
*/



//--------------------------------------------------------
#include "include/parameters_list.h"






class Specifications_player : public QWidget
{
    Q_OBJECT

    QLabel* sex;
    QLabel* name;

    QLabel* portrait;

    Parameters_list param_list;

public:

    Player player;


    explicit Specifications_player(QWidget *parent = nullptr);

public slots:
    void open_spec_slot();
    void update_param_slot();   //обновление характеристик


};



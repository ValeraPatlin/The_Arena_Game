#ifndef SPECIFICATIONS_PLAYER_H
#define SPECIFICATIONS_PLAYER_H

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
//extern Player* player;//---------------------------------------------------------
/*
 * Окно характеристик игрока
 *
*/




class Specifications_player : public QWidget
{
    Q_OBJECT

    QLabel* power;
    QLabel* dexterity;
    QLabel* endurance;
    QLabel* intelligence;
    QLabel* spirit;

    QLabel* level;

    QLabel* sex;
    QLabel* name;

    QLabel* portrait;





    /*
     * parameters
     *
     * power        - сила
     QLabel* dexterity    - ловкость
     QLabel* endurance    - выносливость
     QLabel* intelligence - интелект
     QLabel* spirit       - дух
     *
     */

    QString str;

public:

    Player player;


    explicit Specifications_player(QWidget *parent = nullptr);

public slots:
    void open_spec_slot();
    void update_param_slot();   //обновление характеристик


};

#endif // SPECIFICATIONS_PLAYER_H

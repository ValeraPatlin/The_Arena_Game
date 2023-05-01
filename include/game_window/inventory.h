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
//extern Player* player;//-----------------------------------------------------------
/*
 * Окно инветоря игрока
 *
*/



class Inventory : public QWidget
{
    Q_OBJECT
public:
    explicit Inventory(QWidget *parent = nullptr);

public slots:
    void inventory_open_slot();

};


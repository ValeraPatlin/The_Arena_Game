#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>

#include <QDebug>

#include "include/window/settings.h"
#include "include/window/loading.h"
#include "include/window/character_creation_menu.h"

/*
 * Главное меню игры
 *
 */


class Main_menu : public QWidget
{
    Q_OBJECT

    QPushButton* start;
    QPushButton* loading;
    QPushButton* settings;
    QPushButton* quit;


public:
    Main_menu(QWidget *parent = nullptr);
    ~Main_menu();

public slots:

};


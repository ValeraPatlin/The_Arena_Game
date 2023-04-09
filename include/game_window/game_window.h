#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>

#include <QDebug>

#include "specifications_player.h"
#include "inventory.h"

/*
 * Главное окно игры
 *
*/


class Game_window : public QWidget
{
    Q_OBJECT
public:

    Player player;


    explicit Game_window(QWidget *parent = nullptr);

public slots:
    void start_game_slot();

};

#endif // GAME_WINDOW_H

#include "game_window.h"

Game_window::Game_window(QWidget *parent)
    : QWidget{parent}
{
//window
    Specifications_player* spec_player = new Specifications_player();

    //
    setFixedSize(200, 200);

//button
    QPushButton* spec = new QPushButton("Характеристики");

//connect
    connect(spec, &QPushButton::clicked, [spec_player]()
            {
                spec_player->open_spec_slot();

                spec_player->update_param_slot();
            });

//layout setup

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addWidget(spec);

}

void Game_window::start_game_slot()
{
    this->show();
}

#include "include/game_window/game_window.h"

Game_window::Game_window(QWidget *parent)
    : QWidget{parent}
{
//window
    Specifications_player* spec_player = new Specifications_player();
    Inventory* inventory = new Inventory();

    //
    setFixedSize(200, 200);

//button
    QPushButton* spec = new QPushButton("Характеристики");
    QPushButton* inve = new QPushButton("Инвентарь");

//connect
    connect(spec, &QPushButton::clicked, [this, spec_player]()  //!!!!!!!!
            {
                spec_player->player = this->player;

                // установка портрета
                spec_player->player.portrait = this->player.portrait;

                //обновление на экране параметров персонажа
                spec_player->open_spec_slot();
                spec_player->update_param_slot();
            });

    connect(inve, &QPushButton::clicked, [inventory]()
            {
                inventory->inventory_open_slot();
            });


//layout setup
    //button
    QGroupBox* button_box = new QGroupBox("");
    QVBoxLayout* v_btn_box = new QVBoxLayout();
    v_btn_box->addWidget(spec);
    v_btn_box->addWidget(inve);



    button_box->setLayout(v_btn_box);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addWidget(button_box); //временно


}

void Game_window::start_game_slot()
{
    this->show();
}

#include "include/game_window/specifications_player.h"

Specifications_player::Specifications_player(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Характеристики");

    //setFixedSize(350, 400);  //настроить размер окна


    sex = new QLabel("пол: ");
    name = new QLabel("имя: ");

    portrait = new QLabel();


//Font
    QFont font;
    font.setPixelSize(16);

    sex->setFont(font);
    name->setFont(font);

//layout setup
    //
    QVBoxLayout* name_box = new QVBoxLayout();
    QHBoxLayout* h_box = new QHBoxLayout();

    h_box->addWidget(portrait);

    h_box->addWidget(name);
    h_box->addWidget(sex);

    name_box->addLayout(h_box);

    QGroupBox* skills_box = new QGroupBox("Навыки персонажа");
    //навыка добавить----------------------------------------------------------

    QHBoxLayout* group_box = new QHBoxLayout();
    group_box->addWidget(param_list.param_list(player));

    group_box->addWidget(skills_box);



    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addLayout(name_box);
    main_layout->addSpacing(10);
    main_layout->addLayout(group_box);
    main_layout->addSpacing(10);

}

void Specifications_player::open_spec_slot()
{
    this->show();
}




//обновление характеристик
void Specifications_player::update_param_slot()
{
    param_list.create_parameters_list(player);

    sex->setText("Пол: " + player.sex);
    name->setText("Имя: " + player.name);

    portrait->setPixmap(player.portrait);
}


#include "include/game_window/specifications_player.h"

Specifications_player::Specifications_player(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Характеристики");
    setFixedSize(350, 400);

    power = new QLabel("сила: ");
    dexterity = new QLabel("ловкость: ");
    endurance = new QLabel("выносливость: ");
    intelligence = new QLabel("интелект: ");
    spirit = new QLabel("дух: ");
    level = new QLabel("уровень: ");
    sex = new QLabel("пол: ");
    name = new QLabel("имя: ");

    portrait = new QLabel();


//Font
    QFont font;
    font.setPixelSize(16);
    power->setFont(font);
    dexterity->setFont(font);
    endurance->setFont(font);
    intelligence->setFont(font);
    spirit->setFont(font);
    level->setFont(font);
    sex->setFont(font);
    name->setFont(font);

    /*
     * parameters
     *
     * power        - сила
     * dexterity    - ловкость
     * endurance    - выносливость
     * intelligence - интелект
     * spirit       - дух
     *
    */

//layout setup
    //
    QVBoxLayout* name_box = new QVBoxLayout();
    QHBoxLayout* h_box = new QHBoxLayout();

    h_box->addWidget(portrait);

    h_box->addWidget(name);
    h_box->addWidget(sex);

    name_box->addLayout(h_box);
    name_box->addWidget(level);

    //
    QGroupBox* param = new QGroupBox("Параметры:");
    QVBoxLayout* param_box = new QVBoxLayout();
    param_box->addWidget(power);
    param_box->addWidget(dexterity);
    param_box->addWidget(endurance);
    param_box->addWidget(intelligence);
    param_box->addWidget(spirit);

    param->setFont(font);
    param->setLayout(param_box);

    //
    QGroupBox* skills_box = new QGroupBox("Навыки персонажа");

    QHBoxLayout* group_box = new QHBoxLayout();
    group_box->addWidget(param);
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
    power->setText(power->text() + str.setNum(player.power));
    dexterity->setText(dexterity->text() + str.setNum(player.dexterity));
    endurance->setText(endurance->text() + str.setNum(player.endurance));
    intelligence->setText(intelligence->text() + str.setNum(player.intelligence));
    spirit->setText(spirit->text() + str.setNum(player.spirit));

    level->setText(level->text() + str.setNum(player.level));
    sex->setText(sex->text() + player.sex);
    name->setText(name->text() + player.name);

    portrait->setPixmap(player.portrait);
}


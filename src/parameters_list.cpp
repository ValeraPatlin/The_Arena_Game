#include "include/parameters_list.h"

Parameters_list::Parameters_list()
{
    power = new QLabel();
    dexterity = new QLabel();
    endurance = new QLabel();
    intelligence = new QLabel();
    spirit = new QLabel();
    level = new QLabel();

    hp = new QLabel();
    mana = new QLabel();
    stamina = new QLabel();

    physical_protectio = new QLabel();
    magical_protection = new QLabel();

    physical_attack = new QLabel();
    magical_attack = new QLabel();

    //Font
    QFont font;
    font.setPixelSize(16);
    power->setFont(font);
    dexterity->setFont(font);
    endurance->setFont(font);
    intelligence->setFont(font);
    spirit->setFont(font);
    level->setFont(font);

}

QGroupBox *Parameters_list::param_list(Player &player)
{
    create_parameters_list(player);

    QGroupBox* param_list = new QGroupBox("Параметры:");

    param_list->setMaximumWidth(200);

    QFont font;
    font.setPixelSize(16);
    param_list->setFont(font);

    QFormLayout* param_box = new QFormLayout();
    param_box->addRow("уровень: ", level);

    param_box->addRow("жизни: ", hp);
    param_box->addRow("мана: ", mana);
    param_box->addRow("стамина: ", stamina);

    param_box->addRow("сила: ", power);
    param_box->addRow("ловкость: ", dexterity);
    param_box->addRow("выносливость: ", endurance);
    param_box->addRow("интелект: ", intelligence);
    param_box->addRow("дух: ", spirit);

    param_box->addRow("физ. защита: ", physical_protectio);
    param_box->addRow("маг. защита: ", magical_protection);
    param_box->addRow("физ. атака: ", physical_attack);
    param_box->addRow("маг. атака: ", magical_attack);

    param_list->setLayout(param_box);

    return param_list;
}

//обновление характеристик
void Parameters_list::create_parameters_list(Player &player)
{
    level->setNum(player.level);

    hp->setNum(player.hp);
    mana->setNum(player.mana);
    stamina->setNum(player.stamina);

    power->setNum(player.power);
    dexterity->setNum(player.dexterity);
    endurance->setNum(player.endurance);
    intelligence->setNum(player.intelligence);
    spirit->setNum(player.spirit);

    physical_protectio->setNum(player.physical_protection);
    magical_protection->setNum(player.magical_protection);

    physical_attack->setNum(player.physical_attack);
    magical_attack->setNum(player.magical_attack);
}



#include "form_game_world.h"
#include "ui_form_game_world.h"

Form_game_world::Form_game_world(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_game_world)
{
    ui->setupUi(this);
}

Form_game_world::~Form_game_world()
{
    delete ui;
}

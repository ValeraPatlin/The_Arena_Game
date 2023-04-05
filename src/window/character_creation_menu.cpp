#include "include/window/character_creation_menu.h"

#include <QDebug>

extern Player* player;

Character_creation_menu::Character_creation_menu(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Арена");
    setFixedSize(650, 500);

    str_parameters_point = new QLabel;
    str_parameters_point->setNum(parameters_point);

//button
    QPushButton* start = new QPushButton("Старт");
    QPushButton* quit = new QPushButton("Выход");

    //connect
    //connect(bt, SIGNAL(clicked()), SLOT());
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));


//Fond   ___________
    QFont font;
    font.setPixelSize(16);
    str_parameters_point->setFont(font);
    start->setFont(font);
    quit->setFont(font);

//layout setup    ____________
    //портрет и имя
    QGroupBox* portrait_box = new QGroupBox();


    //параметры персонажа
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
    QGroupBox* parameters_box = new QGroupBox("Параметры персонажа");
    QFormLayout* form = new QFormLayout;

    form->addRow("осталось очков:", str_parameters_point);
    form->addRow("сила:", create_spin_box(player->power));
    form->addRow("ловкость:", create_spin_box(player->dexterity));
    form->addRow("выносливость:", create_spin_box(player->endurance));
    form->addRow("интелект:", create_spin_box(player->intelligence));
    form->addRow("дух:", create_spin_box(player->spirit));
    form->setSpacing(10);

    parameters_box->setLayout(form);

    //навыки и умения
    QGroupBox* skills_box = new QGroupBox("Навыки персонажа");

    //паремметры и навыки
    QGroupBox* parem_skills_box = new QGroupBox("Парамметры и навыки");
    QHBoxLayout* group_box = new QHBoxLayout();
    group_box->addWidget(parameters_box);
    group_box->addWidget(skills_box);

    parem_skills_box->setLayout(group_box);

    //button
    QHBoxLayout* button_box = new QHBoxLayout();
    button_box->addSpacing(100);
    button_box->addWidget(start);
    button_box->addSpacing(100);
    button_box->addWidget(quit);
    button_box->addSpacing(100);

    QVBoxLayout* main_layout = new QVBoxLayout;
    //
    main_layout->addWidget(portrait_box);
    main_layout->addWidget(parem_skills_box);
    main_layout->addLayout(button_box);

    setLayout(main_layout);
}

void Character_creation_menu::start_menu_character_creation_slot()
{
    this->show();
}

//--------------------------------------------------------------
QHBoxLayout* Character_creation_menu::create_spin_box(int& param)
{
    QSpinBox* result = new QSpinBox;

    result->setButtonSymbols(QAbstractSpinBox::NoButtons);
    result->setMaximum(20);
    result->setFixedSize(25, 25);
    result->setReadOnly(true);

    QPushButton* plus = new QPushButton("+");
    QPushButton* minus = new QPushButton("-");

    plus->setFixedSize(25, 30);
    minus->setFixedSize(25, 30);

//Font
    QFont font;
    font.setPixelSize(16);
    result->setFont(font);
    plus->setFont(font);
    minus->setFont(font);

//conntect
    connect(plus, &QPushButton::clicked, [this, result, &param]()
            {
                int num = result->value();
                if (parameters_point != 0)
                {
                    result->setValue(++num);
                    --parameters_point;
                    str_parameters_point->setNum(parameters_point);
                    param = result->value();

                    //test
                    player->print();
                }
            });
    connect(minus, &QPushButton::clicked, [this, result, &param]()
            {
                int num = result->value();
                if (num != 0)
                {
                    result->setValue(--num);
                    ++parameters_point;
                    str_parameters_point->setNum(parameters_point);
                    param = result->value();
                }
            });

    QHBoxLayout* h_box = new QHBoxLayout;

    h_box->addWidget(minus);
    h_box->addWidget(result);
    h_box->addWidget(plus);

    return h_box;
}


void Character_creation_menu::parameters_player_slot()
{
    QString str = ((QPushButton*)sender())->text();

    if (str == "+" && parameters_point != 0)
    {


        --parameters_point;
    }



    qDebug() << "click";
}

#include "include/create_parameters.h"

QFormLayout *create_parameters(int &param_point)
{
    QLabel* str_param_point = new QLabel;
    str_param_point->setNum(param_point);

    QFormLayout* form = new QFormLayout;
    form->addRow("Осталось очков:", str_param_point);
    form->addRow("Сила:", create_spin_box(str_param_point,
                                              param_point, player->power));
    form->addRow("Ловкость:", create_spin_box(str_param_point,
                                                  param_point, player->dexterity));
    form->addRow("Выносливость:", create_spin_box(str_param_point,
                                                      param_point, player->endurance));
    form->addRow("Интелект:", create_spin_box(str_param_point,
                                                  param_point, player->intelligence));
    form->addRow("Дух:", create_spin_box(str_param_point,
                                             param_point, player->spirit));
    form->setSpacing(10);

    return form;
}

QHBoxLayout *create_spin_box(QLabel* str_param_point, int &param_point, int &param)
{
    QSpinBox* spin_box = new QSpinBox;

    spin_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin_box->setMaximum(20);
    spin_box->setFixedSize(25, 25);
    spin_box->setReadOnly(true);

    QPushButton* plus = new QPushButton("+");
    QPushButton* minus = new QPushButton("-");

    plus->setFixedSize(25, 30);
    minus->setFixedSize(25, 30);

    //Font
    QFont font;
    font.setPixelSize(16);
    spin_box->setFont(font);
    str_param_point->setFont(font);
    plus->setFont(font);
    minus->setFont(font);

    //conntect
    QObject::connect(plus, &QPushButton::clicked, [str_param_point, &param_point, spin_box, &param]()
            {
                int num = spin_box->value();
                if (param_point != 0)
                {
                    spin_box->setValue(++num);
                    --param_point;
                    label_param_point(str_param_point, spin_box, param_point, param);
                }
            });
    QObject::connect(minus, &QPushButton::clicked, [str_param_point, &param_point, spin_box, &param]()
            {
                int num = spin_box->value();
                if (num != 0)
                {
                    spin_box->setValue(--num);
                    ++param_point;
                    label_param_point(str_param_point, spin_box, param_point, param);
                }
            });

    QHBoxLayout* h_box = new QHBoxLayout;

    h_box->addWidget(minus);
    h_box->addWidget(spin_box);
    h_box->addWidget(plus);

    return h_box;
}

void label_param_point(QLabel *str_param_point, QSpinBox *spin_box, int &param_point,  int &param)
{
    str_param_point->setNum(param_point);
    param = spin_box->value();

    //test-------------------------------------------------------------------------------------
    player->print();
}


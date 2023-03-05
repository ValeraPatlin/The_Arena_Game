#include "include/settings.h"

int num = 0;
QString text;

Settings::Settings(QWidget *parent)
    : QWidget{parent}
{
//Настройки окна
    setWindowTitle("Настойки");
    setFixedSize(400, 300);
    setWindowFlags(Qt::WindowTitleHint);
    setWindowModality(Qt::ApplicationModal);

//button  _____________
    QPushButton* undo = new QPushButton("Отмена");
    QPushButton* apply = new QPushButton("Применить");
    QPushButton* save = new QPushButton("Созранить");

//connect
    connect(undo, SIGNAL(clicked()), SLOT(close()));

//Radio Button
    QRadioButton* rus = new QRadioButton("&рус");
    QRadioButton* eng = new QRadioButton("&eng");

//Grouo Box
    QGroupBox* language_selection = new QGroupBox(text);
    QHBoxLayout* language_box = new QHBoxLayout;
    language_box->addWidget(rus);
    language_box->addWidget(eng);

    language_selection->setLayout(language_box);

//layout setup    ____________
    QVBoxLayout* main_layout = new QVBoxLayout;

    QHBoxLayout* button_layout = new QHBoxLayout;
    button_layout->addSpacing(50);
    button_layout->addWidget(undo);
    button_layout->addSpacing(15);
    button_layout->addWidget(apply);
    button_layout->addSpacing(15);
    button_layout->addWidget(save);

    main_layout->addWidget(language_selection);
    main_layout->addLayout(button_layout);

    setLayout(main_layout);
}

void Settings::settings_slot()
{
    this->show();
}

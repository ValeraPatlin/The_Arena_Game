#include "include/window/settings.h"

#include <QDebug>

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
    QPushButton* save = new QPushButton("Сохранить");

//connect button
    connect(undo, SIGNAL(clicked()), SLOT(close()));

//Radio Button
    rus = new QRadioButton("&рус");
    eng = new QRadioButton("&eng");

    rus->setChecked(true);

//connect radio button
    connect(rus, SIGNAL(clicked()), SLOT(language_slot()));
    connect(eng, SIGNAL(clicked()), SLOT(language_slot()));

//Grouo Box
    language_selection = new QGroupBox();
    QHBoxLayout* language_box = new QHBoxLayout;
    language_box->addWidget(rus);
    language_box->addWidget(eng);

    language_selection->setTitle("test");   //изменить поле при переводе

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

void Settings::language_slot()
{
    QString str = ((QRadioButton*)sender())->text();

    if (str == "&рус")
    {
        language_selection->setTitle("Выбор языка");

    }
    else
    {
        language_selection->setTitle("Language selection");
    }
}

#include "include/main_menu.h"

Main_menu::Main_menu(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Арена");
    setFixedSize(650, 500);

//button ___________
    QPushButton* start = new QPushButton("Начать");
    QPushButton* loading = new QPushButton("Загрузить");
    QPushButton* settings = new QPushButton("Насторйки");
    QPushButton* quit = new QPushButton("Выход");

//size button   ______
    QSize size_button(170, 50);

    start->setFixedSize(size_button);
    loading->setFixedSize(size_button);
    settings->setFixedSize(size_button);
    quit->setFixedSize(size_button);

//Fond   ___________
    QFont font;
    font.setPixelSize(22);
    start->setFont(font);
    loading->setFont(font);
    settings->setFont(font);
    quit->setFont(font);

//connect   _________
    connect(start, &QPushButton::clicked, [this](){
        this->close();
    });


    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));


    QLabel* heading = new QLabel("Арена");


// layout setup    ____________
    QVBoxLayout* main_layout = new QVBoxLayout;

    QHBoxLayout* label_box = new QHBoxLayout;
    label_box->addSpacing(270);
    label_box->addWidget(heading);

    QVBoxLayout* button_layout = new QVBoxLayout;
    button_layout->addWidget(start);
    button_layout->addSpacing(15);
    button_layout->addWidget(loading);
    button_layout->addSpacing(15);
    button_layout->addWidget(settings);
    button_layout->addSpacing(15);
    button_layout->addWidget(quit);

    QHBoxLayout* center_layout = new QHBoxLayout;
    center_layout->addSpacing(350);
    center_layout->addLayout(button_layout);

    main_layout->addLayout(label_box);
    main_layout->addSpacing(100);
    main_layout->addLayout(center_layout);
    main_layout->addSpacing(200);

    setLayout(main_layout);
}

Main_menu::~Main_menu()
{
}


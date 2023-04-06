#include "include/window/character_creation_menu.h"

#include <QDebug>

extern Player* player;

Character_creation_menu::Character_creation_menu(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Арена");
    setFixedSize(650, 500);

//портрет и имя
    help = new QLabel();
    help->setText("Укажите пол и имя персонажа");

    //portrait
    player_portrait = new QLabel();

    //buttons for portrait
    QPushButton* right = new QPushButton(">");
    QPushButton* left = new QPushButton("<");

    //sex
    men = new QRadioButton("&Мужчина");
    women = new QRadioButton("&Женщина");
    men->setChecked(true);

    //name
    player_name = new QLineEdit();
    player_name->setMaxLength(20);
    player_name->setClearButtonEnabled(true);
    player_name->setPlaceholderText("Enter a character name");

    connect(player_name, &QLineEdit::textEdited, [this]()
            {
                player->name = player_name->text();
            });

//button
    QPushButton* start = new QPushButton("Старт");
    QPushButton* quit = new QPushButton("Выход");

    //connect
    connect(start, SIGNAL(clicked()), SLOT(start_slot()));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

//Fond   ___________
    QFont font;
    font.setPixelSize(16);
    start->setFont(font);
    quit->setFont(font);
    right->setFont(font);
    left->setFont(font);
    men->setFont(font);
    women->setFont(font);
    player_name->setFont(font);
    help->setFont(font);

//layout setup    _________________________________________
//портрет и имя
    QGroupBox* portrait_box = new QGroupBox();

//portait -------------------------------------
    //button
    QHBoxLayout* portait_button = new QHBoxLayout();
    portait_button->addWidget(left);
    portait_button->addWidget(right);

    QVBoxLayout* portait = new QVBoxLayout();
    portait->addWidget(player_portrait);
    portait->addLayout(portait_button);

    //name and sex
    QHBoxLayout* sex_box = new QHBoxLayout();
    sex_box->addWidget(men);
    sex_box->addWidget(women);

    QVBoxLayout* name_box = new QVBoxLayout();
    name_box->addWidget(help);
    name_box->addLayout(sex_box);
    name_box->addSpacing(20);
    name_box->addWidget(player_name);

    //portait box
    QHBoxLayout* main_portait_box = new QHBoxLayout();
    main_portait_box->addLayout(portait);
    main_portait_box->addLayout(name_box);

    portrait_box->setLayout(main_portait_box);

//параметры персонажа ----------------
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
    parameters_box->setFont(font);  //font
    parameters_box->setLayout(create_parameters(parameters_point));

    //навыки и умения
    QGroupBox* skills_box = new QGroupBox("Навыки персонажа");

    skills_box->setFont(font);  //font

    //паремметры и навыки
    QGroupBox* parem_skills_box = new QGroupBox("Парамметры и навыки");
    QHBoxLayout* group_box = new QHBoxLayout();
    group_box->addWidget(parameters_box);
    group_box->addWidget(skills_box);

    parem_skills_box->setFont(font);
    parem_skills_box->setLayout(group_box);

//button for start  ------------------------------
    QHBoxLayout* button_box = new QHBoxLayout();
    button_box->addSpacing(100);
    button_box->addWidget(start);
    button_box->addSpacing(100);
    button_box->addWidget(quit);
    button_box->addSpacing(100);

//main layout -----------------------------------
    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->addWidget(portrait_box);
    main_layout->addWidget(parem_skills_box);
    main_layout->addLayout(button_box);

    setLayout(main_layout);
}

void Character_creation_menu::start_menu_character_creation_slot()
{
    this->show();
}

void Character_creation_menu::start_slot()
{
    if (player_name->text() != "")
    {
        qDebug() << "start";
    }
    else
    {
        help->setText("Укажите имя персонажа!");
        info_widget("Укажите имя персонажа!");
    }
}




void Character_creation_menu::parameters_player_slot() // удалить
{
    QString str = ((QPushButton*)sender())->text();

    if (str == "+" && parameters_point != 0)
    {


        --parameters_point;
    }



    qDebug() << "click";
}

#include "include/window/character_creation_menu.h"

#include "include/create_parameters.h"
#include "include/widget_info.h"

#include "include/game_window/game_window.h"

#include <QDebug>

Character_creation_menu::Character_creation_menu(QWidget *parent)
    : QWidget{parent}
{
//window
    Game_window* game_window = new Game_window();

    setWindowTitle("Арена");
    setFixedSize(1550, 720);

//array
    person_men = {QPixmap(":/pixmap/pixmap/men1.bmp"),
                  QPixmap(":/pixmap/pixmap/men2.bmp")
                  };

    person_women = {QPixmap(":/pixmap/pixmap/women1.bmp"),
                    QPixmap(":/pixmap/pixmap/women2.bmp")
                    };

    str_sex = "Мужчина";    //параметр по умолчанию

//портрет и имя
    help = new QLabel();
    help->setText("Укажите расу, пол и имя персонажа");

    //portrait
    player_portrait = new QLabel();
    player_portrait->setPixmap(person_men[0].scaled(160, 150));
    //установка первоночального портрета


    //тест  -------------------------------------------------------------------------
    //принудительно задать портрет для теста
    //game_window->player.portrait = person_men[0].scaled(160, 150);


    //QPixmap buff(person_men[0].scaled(160, 150));




    //:/pixmap/pixmap/men1.bmp
    //:/pixmap/pixmap/men2.bmp
    //:/pixmap/pixmap/women1.bmp
    //:/pixmap/pixmap/women2.bmp


    //buttons for portrait
    QPushButton* right = new QPushButton(">");
    QPushButton* left = new QPushButton("<");

    connect(right, SIGNAL(clicked()), SLOT(portrait_slot()));
    connect(left, SIGNAL(clicked()), SLOT(portrait_slot()));

    //выбор своего портрета
    QPushButton* open_portrait = new QPushButton("Свой вариант");

    connect(open_portrait, &QPushButton::clicked, [this]()
            {
                QString str_file = QFileDialog::getOpenFileName(
                        this,
                        "Выбор изображения", "../",
                        "All (*);;Images (*.bmp *.jpg *.jpeg *.png)"
                        );

                QPixmap buffer(str_file);
                player_portrait->setPixmap(buffer.scaled(160, 150));
            });




    //раса
    QPushButton* species = new QPushButton("Раса");
    QMenu* menu_species = new QMenu(species);

    menu_species->addAction("Люди");
    menu_species->addAction("Эльфы");

    species->setMenu(menu_species);

    //ToDo: доделать расу
    //установить в классе эту характеристику





    //sex
    men = new QRadioButton("Мужчина");
    women = new QRadioButton("Женщина");
    men->setChecked(true);

    connect(men, SIGNAL(clicked()), SLOT(sex_slot()));
    connect(women, SIGNAL(clicked()), SLOT(sex_slot()));

    //name
    player_name = new QLineEdit();
    player_name->setMaxLength(20);
    player_name->setClearButtonEnabled(true);
    player_name->setPlaceholderText("Enter a character name");

    connect(player_name, &QLineEdit::textEdited, [this]()
            {
                player.name = player_name->text();
            });


//button  -------------------------------------------------------
    QPushButton* start = new QPushButton("Старт");
    QPushButton* quit = new QPushButton("Выход");
    QPushButton* world_settings = new QPushButton("Настройки мира");

    //connect
    connect(start, &QPushButton::clicked, [this, game_window]()  //-----
            {
                QString str = player_name->text();
                if (str != "" && parameters_point == 0
                    && weapon_selected && clothes_selected)
                {
                    game_window->player = this->player;

                    game_window->player.portrait = *player_portrait->pixmap();

                    game_window->start_game_slot();
                    this->close();
                }
                else if (str == "" || str[0] == " ")
                {
                    help->setText("Укажите имя персонажа!");
                    info_widget("Укажите имя персонажа!");
                }
                else if (parameters_point != 0)
                {
                    info_widget("Распределите все очки характеристик!");
                }
                else
                {
                    info_widget("Выберети оружие и одежду!");
                }
            });

    connect(world_settings, &QPushButton::clicked, [this]()
            {
                //сделать настройки мира    --------------------------------------------------------------
            });

    // временно  ---------------------------------------------------------------------------------
    connect(quit, &QPushButton::clicked, qApp, [this]()
            {


                //delete player;      //ToDo: заменить функцией выхода


                qApp->quit();
            });

//Fond   ___________
    QFont font;
    font.setPixelSize(16);
    start->setFont(font);
    quit->setFont(font);
    world_settings->setFont(font);
    right->setFont(font);
    left->setFont(font);
    open_portrait->setFont(font);
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

    QVBoxLayout* portait = new QVBoxLayout();   //портрет персонажа
    portait->addWidget(player_portrait);
    portait->addLayout(portait_button);
    portait->addWidget(open_portrait);

    //name and sex
    QHBoxLayout* sex_box = new QHBoxLayout();
    sex_box->addWidget(men);
    sex_box->addWidget(women);

    //раса
    QHBoxLayout* species_box = new QHBoxLayout();
    species_box->addSpacing(80);
    species_box->addWidget(species);
    species_box->addSpacing(100);







    //ToDo: создать отделный класс
    // выбор предмета в инвентаре  --------------------------------------------------------------------
    QGroupBox* bag_box = new QGroupBox("Выбор экиперовки");
    bag_box->setFont(font);  //font

    QLabel* text_bag = new QLabel("Выберете экиперовку");
    QLabel* money = new QLabel("Количество денег у персонажа: 1000 монет");
    money->setToolTip("Количество денег у персонажа");  //-----------------------------------------------

    QGroupBox* weapon_box = new QGroupBox("Оружие");

    QRadioButton* rusty_sword = new QRadioButton("ржавый меч (-650)");
    rusty_sword->setToolTip("урон 5");
    QRadioButton* baton = new QRadioButton("дубина (0)");
    baton->setToolTip("урон 1");
    QRadioButton* stick = new QRadioButton("деревянный посох (-800)");
    stick->setToolTip("урон 1");

    QVBoxLayout* weapon_layout = new QVBoxLayout();
    weapon_layout->addWidget(rusty_sword);
    weapon_layout->addWidget(baton);
    weapon_layout->addWidget(stick);

    weapon_box->setLayout(weapon_layout);

    QGroupBox* clothes_box = new QGroupBox("Одежда");

    QRadioButton* linen_clothing = new QRadioButton("льняная одежда (-100)");
    QRadioButton* cloth_clothing = new QRadioButton("суконная одежда (-250)");
    QRadioButton* canvas_clothing = new QRadioButton("холщовая одежда (-380)");

    QVBoxLayout* clothes_layout = new QVBoxLayout();
    clothes_layout->addWidget(linen_clothing);
    clothes_layout->addWidget(cloth_clothing);
    clothes_layout->addWidget(canvas_clothing);

    clothes_box->setLayout(clothes_layout);

    QGroupBox* left_hand_box = new QGroupBox("Левая рука");

    QRadioButton* wooden_sewing = new QRadioButton("деревянный шит (-200)");
    QRadioButton* torch = new QRadioButton("факел (-400)");
    QRadioButton* rusty_knife = new QRadioButton("ржавый нож (-350)");
    QRadioButton* left_hand_nothing = new QRadioButton("ничего");

    QVBoxLayout* left_hand_layout = new QVBoxLayout();
    left_hand_layout->addWidget(wooden_sewing);
    left_hand_layout->addWidget(torch);
    left_hand_layout->addWidget(rusty_knife);
    left_hand_layout->addWidget(left_hand_nothing);

    left_hand_box->setLayout(left_hand_layout);


    QGroupBox* armor_box = new QGroupBox("Броня");

    QRadioButton* gambeson = new QRadioButton("гамбезон (-800)");
    QRadioButton* aketon = new QRadioButton("акетон (-900)");

    //Гамбезон  gambeson
    //акетон    aketon

    QRadioButton* armor_nothing = new QRadioButton("ничего");

    QVBoxLayout* armor_layout = new QVBoxLayout();
    armor_layout->addWidget(gambeson);
    armor_layout->addWidget(aketon);
    armor_layout->addWidget(armor_nothing);

    armor_box->setLayout(armor_layout);

    QHBoxLayout* bag_layout = new QHBoxLayout();
    bag_layout->addWidget(weapon_box);
    bag_layout->addWidget(clothes_box);
    bag_layout->addWidget(left_hand_box);
    bag_layout->addWidget(armor_box);

    QVBoxLayout* main_bag_layout = new QVBoxLayout();
    main_bag_layout->addWidget(text_bag);
    main_bag_layout->addWidget(money);
    main_bag_layout->addLayout(bag_layout);

    bag_box->setLayout(main_bag_layout);
    //-----------------------------------------------------------------------------------------









    //
    QVBoxLayout* name_box = new QVBoxLayout();
    name_box->addWidget(help);
    name_box->addLayout(species_box);
    name_box->addLayout(sex_box);
    name_box->addSpacing(20);
    name_box->addWidget(player_name);
    name_box->addSpacing(50);


    // main portait box
    QHBoxLayout* main_portait_box = new QHBoxLayout();
    main_portait_box->addLayout(portait);
    main_portait_box->addLayout(name_box);
    main_portait_box->addWidget(bag_box);
    main_portait_box->addWidget(param_bar.progreess_box()); //индикаторы

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


    // ToDo: доработать установку денег и передать в конец функции create_parameters -> true
    // Уточнение: Возможно не надо!!!!
    parameters_box->setLayout(create_parameters(parameters_point, player, param_list));



    parameters_box->setMaximumWidth(250);



    //надо изменить и удалить
    //навыки и умения
    QGroupBox* skills_box = new QGroupBox("Навыки персонажа");

    skills_box->setFont(font);  //font




    //паремметры и навыки
    QGroupBox* parem_skills_box = new QGroupBox("Парамметры и навыки");
    QHBoxLayout* group_box = new QHBoxLayout();
    group_box->addWidget(parameters_box);
    group_box->addWidget(param_list.param_list(player));
    group_box->addWidget(skills_box);

    parem_skills_box->setFont(font);
    parem_skills_box->setLayout(group_box);

//button for start  ------------------------------
    QHBoxLayout* button_box = new QHBoxLayout();
    button_box->addSpacing(100);
    button_box->addWidget(start);
    button_box->addSpacing(100);
    button_box->addWidget(world_settings);
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

void Character_creation_menu::sex_slot()
{
    str_sex = ((QRadioButton*)sender())->text();

    player.sex = str_sex;

    if (str_sex == "Женщина")
    {
        player_portrait->setPixmap(person_women[0].scaled(160, 150));
    }
    else
    {
        player_portrait->setPixmap(person_men[0].scaled(160, 150));
    }


}

void Character_creation_menu::portrait_slot()
{
    QString str = ((QPushButton*)sender())->text();

    if (str == ">")
    {
        ++index_pixmap;
    }
    else
    {
        --index_pixmap;
    }

    if (index_pixmap >= person_men.size()
        || index_pixmap >= person_women.size()
        || index_pixmap < 0)
    {
        index_pixmap = 0;
    }

    if (str_sex == "Женщина")
    {
        player_portrait->setPixmap(person_women[index_pixmap].scaled(160, 150));

        //player->portrait = person_women[index_pixmap].scaled(160, 150);

        //player->portrait->setPixmap(person_women[index_pixmap].scaled(160, 150));
    }
    else
    {
        player_portrait->setPixmap(person_men[index_pixmap].scaled(160, 150));
    }
}

// Мужчина
// Женщина

//portrait




void Character_creation_menu::parameters_player_slot() // удалить
{
    QString str = ((QPushButton*)sender())->text();

    if (str == "+" && parameters_point != 0)
    {


        --parameters_point;
    }



    qDebug() << "click";
}

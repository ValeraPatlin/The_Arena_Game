#include "form_game.h"
#include "ui_form_game.h"


Form_game::Form_game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_game)
{
    ui->setupUi(this);

    ui->gb_main_from->setMaximumHeight(350);

    // имя персонажа
    ui->le_name->setMaxLength(10);
    ui->le_name->setClearButtonEnabled(true);
    ui->le_name->setPlaceholderText("Введите имя");


    // --------------------------------------
    // Портрет
    portra_elf_men = {QPixmap(":/heroes/pixmap/heroes/e_m1.bmp"),
                      QPixmap(":/heroes/pixmap/heroes/e_m2.bmp"),
                      QPixmap(":/heroes/pixmap/heroes/e_m3.bmp"),};

    portra_elf_women = {QPixmap(":/heroes/pixmap/heroes/e_w1.bmp"),
                        QPixmap(":/heroes/pixmap/heroes/e_w2.bmp"),
                        QPixmap(":/heroes/pixmap/heroes/e_w3.bmp"),};

    portra_people_men = {QPixmap(":/heroes/pixmap/heroes/p_m1.bmp"),
                         QPixmap(":/heroes/pixmap/heroes/p_m2.bmp"),
                         QPixmap(":/heroes/pixmap/heroes/p_m3.bmp"),};

    portra_people_women = {QPixmap(":/heroes/pixmap/heroes/p_w1.bmp"),
                           QPixmap(":/heroes/pixmap/heroes/p_w2.bmp"),
                           QPixmap(":/heroes/pixmap/heroes/p_w3.bmp"),};


    ui->lb_player_portrait->setPixmap(portra_people_men.at(index_portra).scaled(230, 260));


    // подсказка для кнопки выбора своего портрета
    ui->pb_open_portrait->setToolTip("Выберете свой файл для портрета персонажа");
    // --------------------------------------


    // --------------------------------------
    // пол персонажа, по умолчанию выбран мужчина
    ui->rb_men->setChecked(true);
    // --------------------------------------










    // --------------------------------------
    // расса
    ui->cb_species->addItems(QStringList() << "люди" << "эльфы");

    // описание рассы
    species_people_plus();   // по умолчанию выбран человек
    species = "люди";
    // --------------------------------------


    // --------------------------------------
    // Характеристики
    //ui->scroll_parameter->setMinimumWidth(100);
    ui->gb_parameter->setFixedWidth(280);

    setting_initial_characteristics();
    // --------------------------------------


    // --------------------------------------
    //Предыстория персонажа

    // -------------------------------------



    // -------------------------------------
    // описание
    QString str_description = ""; // может быть зделать загрузку описания всех характеристик из файла

    ui->lb_description->setText(str_description);
    // -------------------------------------



    // Распределение очков
    ui->sb_power->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->sb_dexterity->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->sb_endurance->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->sb_intelligence->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->sb_spirit->setButtonSymbols(QAbstractSpinBox::NoButtons);

    ui->sb_power->setReadOnly(true);
    ui->sb_dexterity->setReadOnly(true);
    ui->sb_endurance->setReadOnly(true);
    ui->sb_intelligence->setReadOnly(true);
    ui->sb_spirit->setReadOnly(true);

    ui->lb_points_param->setText(QString::number(leveling_points_parameter));
    // -------------------------------------------------------------------------------

    //

}

Form_game::~Form_game()
{
    delete ui;
}


// переход к главному меню
void Form_game::on_pd_mein_menu_clicked()
{
    main_window->setVisible(true);
    close();
}

//параметры персонажа основные
/*
     * parameters
     *
     * Жизнь    - 50
     * Мана     - 10
     * Стамина  - 20
     *
     * power        - сила          (жизнь +2, сила +1, физ. атака +1)
     * dexterity    - ловкость      (ловкость +1, физ. защита +1)
     * endurance    - выносливость  (жизнь +1, стамина +5, выносливость +1)
     * intelligence - интелект      (мана +2, интелект +1, маг. атака +1)
     * spirit       - дух           (мана +5, дух +1, маг. защита +1)
     *
     *---------------------
     * физ. защита  physical protection
     * маг. защита  magical protection
     *
     * физ. атака   physical attack
     * маг. атака   magic attack
     *
     * ---------------------
     *
     * hp       - жизни     (50)    - изначальные данные
     * mana     - мана      (10)
     * stamina  - стамина   (20)    (энергия для удара)
     *
     *
     */

// --------------------------------------------------------------------
// установка характеристик
void Form_game::setting_initial_characteristics()
{
    // уровень, жизнь, мана, стамина
    ui->label_level->setText(QString::number(player.level));
    ui->label_hp->setText(QString::number(player.hp));
    ui->label_mana->setText(QString::number(player.mana));
    ui->label_stamina->setText(QString::number(player.stamina));

    // основные
    ui->label_power->setText(QString::number(player.power));
    ui->label_dexterity->setText(QString::number(player.dexterity));
    ui->label_endurance->setText(QString::number(player.endurance));
    ui->label_intelligence->setText(QString::number(player.intelligence));
    ui->label_spirit->setText(QString::number(player.spirit));

    // защита
    ui->lb_armor->setText(player.armor);
    ui->label_physical_protection->setText(QString::number(player.physical_protection));
    ui->label_magical_protection->setText(QString::number(player.magical_protection));
    ui->lb_parrying->setText(QString::number(player.parrying));
    ui->lb_evasion->setText(QString::number(player.evasion));

    // атака
    ui->label_physical_attack->setText(QString::number(player.physical_attack));
    ui->label_magical_attack->setText(QString::number(player.magical_attack));
    ui->lb_chance_hit->setText(QString::number(player.chance_hit) + " %");     // шанс крит. удара
    ui->lb_critical_hit->setText(QString::number(player.critical_hit) + " %"); // крит. удар

        // точность
    ui->lb_close_combat->setText(QString::number(player.close_combat));
    ui->lb_ranged_combat->setText(QString::number(player.ranged_combat));
    //маг.атака
    ui->lb_accuracy_magical_hit->setText(QString::number(player.accuracy_magical_hit) + " %");

    // пробивание брони
    ui->lb_armor_pierc_close->setText(QString::number(player.armor_piercing_close) + " %");
    ui->lb_armor_pierc_ranged->setText(QString::number(player.armor_piercing_ranged) + " %");
    ui->lb_armor_pierc_magical->setText(QString::number(player.armor_piercing_magical) + " %");
    // ближний бой
    // дальний бой
    // маг. атака
}
// --------------------------------------------------------------------



// ---------------------------------------------------------------------
// Кнопки увеличения и уменьшения характеристик
bool Form_game::plus_point_parameter()
{
    if (leveling_points_parameter != 0)
    {
        --leveling_points_parameter;
        ui->lb_points_param->setText(QString::number(leveling_points_parameter));

        return true;
    }
    return false;
}

bool Form_game::minus_point_parameter()
{
    if (leveling_points_parameter != 10)
    {
        ++leveling_points_parameter;
        ui->lb_points_param->setText(QString::number(leveling_points_parameter));

        return true;
    }
    return false;
}

/*
 методы для увеличения/уменьшения характеристик и бонусов:
    power - сила (жизнь +2, сила +1, физ. атака +1)

    dexterity - ловкость (ловкость +1, защита: парирование +1, уклонение +1,
        точность: ближний бой +1, дальний бой +1)

    endurance - выносливость (жизнь +1, стамина +5, выносливость +1)

    intelligence - интелект (мана +2, интелект +1, маг. атака +1)

    spirit  - дух (мана +5, дух +1, маг. защита +1)


    шанс критического удара - с каждым очком ловкости +0.5
    критический удар - зависит от сылы, каждые очко силы +2 крит.удар


    accuracy_magical_hit - точность маг. атака:
        точность маг атаки увеличивается при помощи интелекта, (!!! в будущем еще и будут навыки !!!)
        за первое очко, если до этого был ноль, дается +10
        за последующие очки по 2


    пробивание брани:
    armor_piercing_close - ближний бой, Это шанс пробить броню и нанести дополнительный урон
    первоночально равен 0.2 зависит от сылы, за каждое очко сылы увеличивается на 0.2

    armor_piercing_ranged - дальний бой, зависит от ловкости +0.1
        (!!! в будущем будет ещё зависит от оружия !!!)

    armor_piercing_magical - маг. атака, зависит от интелекта +0.5,
    первоночально равен нулю, за первое очко интелекта дается +2

*/


    // сила (+/-)
void Form_game::power_plus()
{
    player.hp += 2;
    player.power += 1;
    player.physical_attack += 1;
    player.critical_hit = player.physical_attack + 2;   // крит.удар
    player.armor_piercing_close += 0.2;     // пробивание брани ближний бой
}

void Form_game::power_minus()
{
    player.hp -= 2;
    player.power -= 1;
    player.physical_attack -= 1;

    // расчет крит.удара
    if (player.physical_attack == 1)
    {
        player.critical_hit = 2;
    }
    else
    {
        player.critical_hit = player.physical_attack + 2;
    }

    player.armor_piercing_close -= 0.2;     // пробивание брани ближний бой
}

    // ловкость (+/-)
void Form_game::dexterity_plus()
{
    player.dexterity += 1;
    player.parrying += 1;   // парирование
    player.evasion += 1;    // уклонение
    player.close_combat += 1;   // ближний бой
    player.ranged_combat += 1;  // дальний бой
    player.armor_piercing_ranged += 0.1;    // пробивание брани дальний бой
}

void Form_game::dexterity_minus()
{
    player.dexterity -= 1;
    player.parrying -= 1;   // парирование
    player.evasion -= 1;    // уклонение
    player.close_combat -= 1;   // ближний бой
    player.ranged_combat -= 1;  // дальний бой

    // пробивание брани дальний бой
    if (player.dexterity == 0)  // что бы правельно считало
    {
        player.armor_piercing_ranged = 0;
    }
    else
    {
        player.armor_piercing_ranged -= 0.1;
    }
}

    // выносливость (+/-)
void Form_game::endurance_plus()
{
    player.hp += 1;
    player.stamina += 5;
    player.endurance += 1;
}

void Form_game::endurance_minus()
{
    player.hp -= 1;
    player.stamina -= 5;
    player.endurance -= 1;
}

    // интелект (+/-)
void Form_game::intelligence_plus()
{
    player.mana += 2;
    player.intelligence += 1;
    player.magical_attack += 1;

    // расчет точности маг. атаки
    if (player.intelligence == 1)
    {
        player.accuracy_magical_hit += 10;
    }
    else
    {
        player.accuracy_magical_hit += 2;
    }

    // расчет пробивание брони маг. атакой
    if (player.intelligence == 1)
    {
        player.armor_piercing_magical += 2;
    }
    else
    {
        player.armor_piercing_magical += 0.5;
    }
}

void Form_game::intelligence_minus()
{
    player.mana -= 2;
    player.intelligence -= 1;
    player.magical_attack -= 1;

    // расчет точности маг. атаки
    if (player.intelligence == 0)
    {
        player.accuracy_magical_hit = 0;
    }
    else
    {
        player.accuracy_magical_hit -= 2;
    }

    // расчет пробивание брони маг. атакой
    if (player.intelligence == 0)
    {
        player.armor_piercing_magical = 0;
    }
    else
    {
        player.armor_piercing_magical -= 0.5;
    }
}

    // дух (+/-)
void Form_game::spirit_plus()
{
    player.mana += 5;
    player.spirit += 1;
    player.magical_protection += 1;
}

void Form_game::spirit_minus()
{
    player.mana -= 5;
    player.spirit -= 1;
    player.magical_protection -= 1;
}


// power - сила (жизнь +2, сила +1, физ. атака +1)
void Form_game::on_pb_power_plus_clicked()
{
    if (plus_point_parameter())
    {
        ui->sb_power->stepUp();
        power_plus();
        setting_initial_characteristics();
    }
}

void Form_game::on_pb_power_minus_clicked()
{
    if (ui->sb_power->value() != 0 && minus_point_parameter())
    {
        ui->sb_power->stepDown();
        power_minus();
        setting_initial_characteristics();
    }
}

// dexterity - ловкость (ловкость +1, защита: парирование +1, уклонение +1, точность: ближний бой +1, дальний бой +1)
void Form_game::on_pb_dexterity_plus_clicked()
{
    if (plus_point_parameter())
    {
        ui->sb_dexterity->stepUp();
        dexterity_plus();
        setting_initial_characteristics();
    }
}

void Form_game::on_pb_dexterity_minus_clicked()
{
    if (ui->sb_dexterity->value() != 0 && minus_point_parameter())
    {
        ui->sb_dexterity->stepDown();
        dexterity_minus();
        setting_initial_characteristics();
    }
}

// endurance - выносливость (жизнь +1, стамина +5, выносливость +1)
void Form_game::on_pb_endurance_plus_clicked()
{
    if (plus_point_parameter())
    {
        ui->sb_endurance->stepUp();
        endurance_plus();
        setting_initial_characteristics();
    }
}

void Form_game::on_pb_endurance_minus_clicked()
{
    if (ui->sb_endurance->value() != 0 && minus_point_parameter())
    {
        ui->sb_endurance->stepDown();
        endurance_minus();
        setting_initial_characteristics();
    }
}

// intelligence - интелект (мана +2, интелект +1, маг. атака +1)
void Form_game::on_pb_intelligence_plus_clicked()
{
    if (plus_point_parameter())
    {
        ui->sb_intelligence->stepUp();
        intelligence_plus();
        setting_initial_characteristics();
    }
}

void Form_game::on_pb_intelligence_minus_clicked()
{
    if (ui->sb_intelligence->value() != 0 && minus_point_parameter())
    {
        ui->sb_intelligence->stepDown();
        intelligence_minus();
        setting_initial_characteristics();
    }
}

// spirit  - дух (мана +5, дух +1, маг. защита +1)
void Form_game::on_pb_spirit_plus_clicked()
{
    if (plus_point_parameter())
    {
        ui->sb_spirit->stepUp();
        spirit_plus();
        setting_initial_characteristics();
    }
}

void Form_game::on_pb_spirit_minus_clicked()
{
    if (ui->sb_spirit->value() != 0 && minus_point_parameter())
    {
        ui->sb_spirit->stepDown();
        spirit_minus();
        setting_initial_characteristics();
    }
}
// -------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------
// Выбор своевго файла для портрета персонажа
void Form_game::on_pb_open_portrait_clicked()
{
    QString str_file = QFileDialog::getOpenFileName(
        this,
        "Выбор изображения", "..",
        "All (*);;Images (*.bmp *.jpg *.jpeg *.png)"
        );

    QPixmap buffer(str_file);
    ui->lb_player_portrait->setPixmap(buffer.scaled(160, 150));
}
// ------------------------------------------------------------------------------------------



// -------------------------------------------------------------------------------
// выбор рассы
    // эльфы  -------------------------------------------------------------
void Form_game::species_elves_plus()
{
    ui->lb_species_help->setText("Эльфы имеют большию предрасположенность к магии \n"
                                 "и более ловкие чем остальные рассы \n"
                                 "Но эльфы менее жывучи чем остальные рассы \n"
                                 "бонус к: \n"
                                 "\t -ловкость +1 \n"
                                 "\t -мана + 5 \n"
                                 "\t -маг. защите +1 \n"
                                 "\t -маг. атаки +1 \n"
                                 "минус к: \n"
                                 "\t -жизнь -5"
                                 );

    player.magical_protection += 1;
    player.magical_attack += 1;
    player.mana += 5;
    dexterity_plus();   // +1 ловкость и всё что даёт ловкость -----
    player.hp -= 5; // минусы (жизнь -5)

    setting_initial_characteristics();

    // Установка портрета
    if (ui->rb_men->isChecked())
    {
        ui->lb_player_portrait->setPixmap(portra_elf_men.at(0).scaled(230, 260));
    }
    else
    {
        ui->lb_player_portrait->setPixmap(portra_elf_women.at(0).scaled(230, 260));
    }
}

void Form_game::species_elves_minus()
{
    player.magical_protection -= 1;
    player.magical_attack -= 1;
    player.mana -= 5;
    dexterity_minus();   // -1 ловкость и всё что даёт ловкость -----
    player.hp += 5; // минусы убираются (жизнь +5)
}

    // -----------------------------------------------------------------
    // люди -----------------------------------------------------------
void Form_game::species_people_plus()
{
    ui->lb_species_help->setText("Люди более выносливы \n"
                                 "бонус к: \n"
                                 "\t -выносливость +1 \n"
                                 "\t -жизнь +1 \n"
                                 "\t -стамина +5 \n"
                                 "минусы: \n"
                                 "\t -нет");
    endurance_plus();   // +1 выносливость и всё что даёт выносливость -----
    setting_initial_characteristics();

    // Установка портрета
    if (ui->rb_men->isChecked())
    {
        ui->lb_player_portrait->setPixmap(portra_people_men.at(index_portra).scaled(230, 260));
    }
    else
    {
        ui->lb_player_portrait->setPixmap(portra_people_women.at(index_portra).scaled(230, 260));
    }
}

void Form_game::species_people_minus()
{
    endurance_minus();  // -1 выносливость и всё что даёт выносливость -----
}
    // -----------------------------------------------------------------

    // здесь удаляются бонусы предыдущей рассы (и минусы тоже)
    // это специально для добавления других расс (если рас будет больше чем две)
void Form_game::on_cb_species_textActivated(const QString &arg1)
{
    if (species == "люди")
    {
        species_people_minus();
    }
    else if (species == "эльфы")
    {
        species_elves_minus();
    }

    if (arg1 == "эльфы")
    {
        species_elves_plus();
    }
    else if (arg1 == "люди")
    {
        species_people_plus();
    }

    species = arg1;
}
// -----------------------------------------------------------------------------



// ---------------------------------------------------------------
// переключение портретов
void Form_game::on_rb_men_clicked()
{
    if (ui->cb_species->currentText() == "эльфы")
    {
        ui->lb_player_portrait->setPixmap(portra_elf_men.at(index_portra).scaled(230, 260));
    }
    else if (ui->cb_species->currentText() == "люди")
    {
        ui->lb_player_portrait->setPixmap(portra_people_men.at(index_portra).scaled(230, 260));
    }
}

void Form_game::on_rb_women_clicked()
{
    if (ui->cb_species->currentText() == "эльфы")
    {
        ui->lb_player_portrait->setPixmap(portra_elf_women.at(index_portra).scaled(230, 260));
    }
    else if (ui->cb_species->currentText() == "люди")
    {
        ui->lb_player_portrait->setPixmap(portra_people_women.at(index_portra).scaled(230, 260));
    }
}
    // этот метод специально для кнопок вперёд и назад, так как код повторялся
void Form_game::switching_portraits()
{
    if (ui->cb_species->currentText() == "эльфы")
    {
        if (ui->rb_men->isChecked())
        {
            ui->lb_player_portrait->setPixmap(portra_elf_men.at(index_portra).scaled(230, 260));
        }
        else
        {
            ui->lb_player_portrait->setPixmap(portra_elf_women.at(index_portra).scaled(230, 260));
        }
    }
    else if (ui->cb_species->currentText() == "люди")
    {
        if (ui->rb_men->isChecked())
        {
            ui->lb_player_portrait->setPixmap(portra_people_men.at(index_portra).scaled(230, 260));
        }
        else
        {
            ui->lb_player_portrait->setPixmap(portra_people_women.at(index_portra).scaled(230, 260));
        }
    }

}

void Form_game::on_pb_back_clicked()    // кнопка назад
{
    --index_portra;

    if (index_portra < 0)
    {
        index_portra = MAX_NUMBER_ELEMET;
    }

    switching_portraits();
}

void Form_game::on_pb_forward_clicked() // кнопка вперёд
{
    ++index_portra;

    if (index_portra == MAX_COUNT_PORTRA || index_portra < 0)
    {
        index_portra = 0;
    }

    if (index_portra == MAX_COUNT_PORTRA)
    {
        index_portra = 0;
    }

    switching_portraits();
}
// --------------------------------------------------------------------



// ----------------------------------------------------------------------------
// Сохранения созданного персонажа
void Form_game::on_pb_save_player_clicked()
{
    QString file_str = QFileDialog::getSaveFileName(this,
                                                    "Сохранения персонажа", "./",
                                                    "All (*);;Images (*.json)");

    qDebug() << file_str;
}
// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
// Загрузка персонажа
void Form_game::on_pb_loading_clicked()
{
    QString file_str = QFileDialog::getOpenFileName(this,
                                                    "Загрузка персонажа", "./",
                                                    "All (*);;Images (*.json)");

     qDebug() << file_str;
}
// -----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// проверка имени
bool Form_game::name_verification()
{
    QString str_buffer = ui->le_name->text();
    QString str_name = str_buffer.simplified();

    std::vector<char> vec = {'*', '.', ',', '/', '\\', '|', ':', ';', '!', '=', '<', '>',
                             '@', '#', '$', '%', '^', '&', '(', ')', '+', '`', '~', '1', '?',
                             '2', '3', '4', '5', '6', '7', '8', '9', '0', '[', ']', '{', '}'};

    for (const auto& it : vec)
    {
        if (str_name.contains(it))
        {
            return false;
        }
    }

    qDebug() << str_name;

    return true;
}
// ---------------------------------------------------------------------------


// --------------------------------------------------------------------------
// кнопка старт
void Form_game::on_pb_start_clicked()
{
    bool good_start = true;
    QString str = "";

    if (leveling_points_parameter != 0)
    {
        good_start = false;
        str += "Распределите все очки характеристик. \n";
    }

    if (!name_verification())
    {
        good_start = false;
        str += "Придумайте корректное имя персонажа \n"
               "без использования чисел и знаков: .,!@#$%^&*(`~:;[{|+_-=<> \n";
    }

    if (ui->le_name->text() == "")
    {
        good_start = false;
        str += "Придумайте имя персонажа. \n";
    }

    if (good_start)
    {
        //
    }
    else
    {
        QMessageBox::information(this, "Внимание!",
                                 str);
    }
}
//------------------------------------------------------------------------------



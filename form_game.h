#ifndef FORM_GAME_H
#define FORM_GAME_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <vector>
#include "player.h"
#include <QDebug>

namespace Ui {
class Form_game;
}

class Form_game : public QWidget
{
    Q_OBJECT

    // первоначальные очки прокачки
    int leveling_points_parameter = 10;

    bool plus_point_parameter();
    bool minus_point_parameter();

    // создание игрока
    Player player;

    // расса по умолчанию
    QString species;


    // ---------------------------------------
    // портреты героев
    std::vector<QPixmap> portra_elf_men;
    std::vector<QPixmap> portra_elf_women;

    std::vector<QPixmap> portra_people_men;
    std::vector<QPixmap> portra_people_women;

    int index_portra{};
    // --------------------------------------------


    // проверка имени
    bool name_verification();

    // Характеристики
    void setting_initial_characteristics();

    // метод для добавления бонусов рассе
    void species_people_plus(); // люди
    void species_people_minus();

    void species_elves_plus();  // эльфы
    void species_elves_minus();

    // ------------------------------------------------------------------
    // методы для увеличения/уменьшения характеристик и бонусов
        // сила (+/-)
    void power_plus();
    void power_minus();

        // ловкость (+/-)
    void dexterity_plus();
    void dexterity_minus();

        // выносливость (+/-)
    void endurance_plus();
    void endurance_minus();

        // интелект (+/-)
    void intelligence_plus();
    void intelligence_minus();

        // дух (+/-)
    void spirit_plus();
    void spirit_minus();
    // ---------------------------------------------------------------------

public:
    explicit Form_game(QWidget *parent = nullptr);
    ~Form_game();

private slots:

    // ----------------------------------------------------------------
    // Кнопки увеличения и уменьшения характеристик
    void on_pd_mein_menu_clicked();
    void on_pb_power_plus_clicked();
    void on_pb_power_minus_clicked();
    void on_pb_dexterity_plus_clicked();
    void on_pb_dexterity_minus_clicked();
    void on_pb_endurance_plus_clicked();
    void on_pb_endurance_minus_clicked();
    void on_pb_intelligence_plus_clicked();
    void on_pb_intelligence_minus_clicked();
    void on_pb_spirit_plus_clicked();
    void on_pb_spirit_minus_clicked();
    // ----------------------------------------------------------------

    void on_pb_open_portrait_clicked();

    void on_cb_species_textActivated(const QString &arg1);

    void on_pb_save_player_clicked();

    void on_pb_start_clicked();

    void on_rb_men_clicked();

    void on_rb_women_clicked();

    void on_pb_back_clicked();

    void on_pb_forward_clicked();

    void on_pb_loading_clicked();

private:
    Ui::Form_game *ui;
};

#endif // FORM_GAME_H

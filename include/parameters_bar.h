#pragma once

#include <QProgressBar>
#include <QGroupBox>
#include <QBoxLayout>

/*
 * создание виджета для индикаторов

 * hp_bar           - жизни
 * mana_bar         - мана
 * endurance_bar    - выносливость
 *
 * Функция progreess_box() устанавливает индикаторы
 * для основных параметров
 *
 *          // Может всё в отдельный класс???   -----------------------------------------
 *          // надо подумать
 */

class Parameters_bar
{
public:
    Parameters_bar();


    //индикаторы
    QProgressBar* hp_bar;
    QProgressBar* mana_bar;
    QProgressBar* stamina_bar;

    //ToDo: добавить индикатор опыта

    //
    QGroupBox *progreess_box();

    QProgressBar* create_prog_bar(QProgressBar* prog_bar, int max);

    //функция изменения бара

private:
    //установка стилей
    //состояние норма
    void hp_bar_style();
    void mana_bar_style();
    void stamina_bar_stylea();
    //ресурс исчерпан на половину
    //критическое состояние


};



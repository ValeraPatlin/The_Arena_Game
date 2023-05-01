#include "include/parameters_bar.h"

Parameters_bar::Parameters_bar()
{

}

/*
 * пример вызова изменения максимального количества очков
 * вы баре
 *
 * param_bar.create_prog_bar(param_bar.hp_bar, 20);
 *
 */



void Parameters_bar::hp_bar_style()
{
    hp_bar->setStyleSheet("QProgressBar{"
                          "border: 1px solid transparent;text-align: center;"

                          "color:rgba(255,255,250,255);"  //цвет текста

                          "border-radius: 5px;"   // закругление по углам
                          "border-width: 3px;"    // толщина обводки в пикселях
                          "border-image: 9,2,5,2; "

                          "background-color: "
                          "qlineargradient(spread:pad, x1:0, y1:0,""x2:1, y2:1, "

                          "stop:0 rgba(220, 220, 220, 200),"   // цвет незаполненой шкалы вверх
                          "stop:1 rgba(20, 20, 20, 200));"     // низ
                          "}"

                          "QProgressBar::chunk "
                          "{background-color: "
                          "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"

                          "stop: 0 rgba(173, 255, 47, 255),"  // цвет главной линии верх
                          "stop: 1 rgba(0, 100, 0,255));}");  // низ
}

void Parameters_bar::mana_bar_style()
{
    mana_bar->setStyleSheet("QProgressBar{"
                            "border: 1px solid transparent;text-align: center;"

                            "color:rgba(255,255,250,255);"  //цвет текста

                            "border-radius: 5px;"   // закругление по углам
                            "border-width: 3px;"    // толщина обводки в пикселях
                            "border-image: 9,2,5,2; "

                            "background-color: "
                            "qlineargradient(spread:pad, x1:0, y1:0,""x2:1, y2:1, "

                            "stop:0 rgba(220, 220, 220, 200),"   // цвет незаполненой шкалы вверх
                            "stop:1 rgba(20, 20, 20, 200));"     // низ
                            "}"
                            "QProgressBar::chunk "
                            "{background-color: "
                            "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"

                            "stop: 0 rgba(0, 255, 255, 255),"
                            "stop: 1 rgba(0, 0, 139, 255));}");
}

void Parameters_bar::stamina_bar_stylea()
{
    stamina_bar->setStyleSheet("QProgressBar{"
                                 "border: 1px solid transparent;text-align: center;"

                                 "color:rgba(255,255,250,255);"  //цвет текста

                                 "border-radius: 5px;"   // закругление по углам
                                 "border-width: 3px;"    // толщина обводки в пикселях
                                 "border-image: 9,2,5,2; "

                                 "background-color: "
                                 "qlineargradient(spread:pad, x1:0, y1:0,""x2:1, y2:1, "

                                 "stop:0 rgba(220, 220, 220, 200),"   // цвет незаполненой шкалы вверх
                                 "stop:1 rgba(20, 20, 20, 200));"     // низ
                                 "}"
                                 "QProgressBar::chunk "
                                 "{background-color: "
                                 "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"

                                 "stop: 0 rgba(255, 235, 205, 255),"
                                 "stop: 1 rgba(210, 105, 30, 255));}");
}

QGroupBox *Parameters_bar::progreess_box()
{
    //индикаторы   -----------------------------------------------------------------------
    hp_bar = new QProgressBar();
    mana_bar = new QProgressBar();
    stamina_bar = new QProgressBar();

    hp_bar_style();
    mana_bar_style();
    stamina_bar_stylea();

    QGroupBox* progreess_box = new QGroupBox();
    QVBoxLayout* prog_box = new QVBoxLayout();
    prog_box->addWidget(create_prog_bar(hp_bar, 50));
    prog_box->addWidget(create_prog_bar(mana_bar, 10));
    prog_box->addWidget(create_prog_bar(stamina_bar, 20));

    progreess_box->setLayout(prog_box);

    return progreess_box;
}

QProgressBar *Parameters_bar::create_prog_bar(QProgressBar *prog_bar, int max)
{
    prog_bar->setRange(0, max);
    prog_bar->setValue(max);

    return prog_bar;
}



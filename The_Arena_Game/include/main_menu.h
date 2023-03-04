#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>

class Main_menu : public QWidget
{
    Q_OBJECT

    //QPushButton* start;
    //QPushButton* loading;
    //QPushButton* settings;
    //QPushButton* quit;

public:
    Main_menu(QWidget *parent = nullptr);
    ~Main_menu();
};
#endif // MAIN_MENU_H

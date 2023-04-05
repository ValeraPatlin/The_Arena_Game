#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>
#include <QGroupBox>
#include <QRadioButton>
#include <QString>

/*
 * Меню параметров игры
 *
 */


class Settings : public QWidget
{
    Q_OBJECT
    QGroupBox* language_selection;
    QRadioButton* rus;
    QRadioButton* eng;



public:
    explicit Settings(QWidget *parent = nullptr);

public slots:
    void settings_slot();

private slots:
    void language_slot();

};


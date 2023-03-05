#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QFont>
#include <QGroupBox>
#include <QRadioButton>
#include <QString>

extern int num;

#if num > 0

QString text = "eng";

#else

//extern QString text = "рус";

#endif


class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);

public slots:
    void settings_slot();

};

#endif // SETTINGS_H

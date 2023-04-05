#pragma once

#include <QWidget>

/*
 *Меню загрузок игры
 *
 */

class Loading : public QWidget
{
    Q_OBJECT
public:
    explicit Loading(QWidget *parent = nullptr);

public slots:
    void loading_slot();

};



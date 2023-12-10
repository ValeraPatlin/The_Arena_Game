#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>

#include "form_game.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window; }
QT_END_NAMESPACE

class Main_Window : public QWidget
{
    Q_OBJECT

    Form_game* form_game;

public:
    Main_Window(QWidget *parent = nullptr);
    ~Main_Window();

private slots:
    void on_pb_start_clicked();

    void on_pb_exit_clicked();

private:
    Ui::Main_Window *ui;

protected:
    void closeEvent(QCloseEvent* event = nullptr) override;
};
#endif // MAIN_WINDOW_H

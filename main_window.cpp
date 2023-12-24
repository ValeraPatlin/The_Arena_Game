#include "main_window.h"
#include "qevent.h"
#include "ui_main_window.h"


Main_Window::Main_Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);

    //
    form_game = new Form_game();
    form_game->main_window = this;
    //

    ui->label_version->setText ("0.0.2");
}

Main_Window::~Main_Window()
{
    delete ui;
}


void Main_Window::on_pb_start_clicked()
{
    form_game->show();
    this->setVisible(false);
}

void Main_Window::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton result;
    result= QMessageBox::question(this, "Выход из игры",
                                   "Вы дествиельно хотите выйти?",
                                   QMessageBox::Yes | QMessageBox::No,
                                   QMessageBox::No);

    if (event)
    {
        if (result == QMessageBox::Yes)
        {
            event->accept();
            QWidget::closeEvent(event);
        }
        else
        {
            event->ignore();
        }
    }
    else
    {
        if (result == QMessageBox::Yes)
        {
            QApplication::quit();
        }
    }
}


void Main_Window::on_pb_exit_clicked()
{
    closeEvent();
}


#include "include/widget_info.h"

void info_widget(QString text)
{
    QWidget* win = new QWidget();
    win->setWindowTitle("Error!");
    win->setFixedSize(350, 150);
    win->setWindowFlags(Qt::WindowTitleHint);
    win->setWindowModality(Qt::ApplicationModal);
    win->setWindowIcon(QIcon(":/Icon_window/icon/win_error.bmp"));

    QLabel* label= new QLabel(text);
    label->setAlignment(Qt::AlignCenter);

    QPushButton* btn_ok = new QPushButton("Ok");
    btn_ok->setFixedSize(70, 35);

    QObject::connect(btn_ok, SIGNAL(clicked()), win, SLOT(close()));

//Fond   ___________
    QFont font;
    font.setPixelSize(16);
    label->setFont(font);
    btn_ok->setFont(font);

// layout setup
    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->addWidget(btn_ok, Qt::AlignCenter);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->addWidget(label);
    vbox->addLayout(hbox);

    win->setLayout(vbox);

    QApplication::beep();  //не работает

    win->show();
}



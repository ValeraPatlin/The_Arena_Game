#include "include/window/main_menu.h"
#include "include/creature/player.h"


#include <QApplication>

Player* player = new Player();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main_menu w;
    w.show();
    return a.exec();
}

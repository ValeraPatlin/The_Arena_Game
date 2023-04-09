#include "include/window/main_menu.h"
#include "include/creature/player.h"


#include <QApplication>

//Player* player = new Player();



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Main_menu win;
    win.show();

    return app.exec();
}

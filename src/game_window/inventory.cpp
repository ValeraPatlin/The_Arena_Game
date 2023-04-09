#include "include/game_window/inventory.h"

Inventory::Inventory(QWidget *parent)
    : QWidget{parent}
{

}

void Inventory::inventory_open_slot()
{
    this->show();
}

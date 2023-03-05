#include "include/loading.h"

Loading::Loading(QWidget *parent)
    : QWidget{parent}
{

}

void Loading::loading_slot()
{
    this->show();
}

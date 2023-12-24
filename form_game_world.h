#ifndef FORM_GAME_WORLD_H
#define FORM_GAME_WORLD_H

#include <QWidget>

namespace Ui {
class Form_game_world;
}

class Form_game_world : public QWidget
{
    Q_OBJECT

public:
    explicit Form_game_world(QWidget *parent = nullptr);
    ~Form_game_world();

private:
    Ui::Form_game_world *ui;
};

#endif // FORM_GAME_WORLD_H

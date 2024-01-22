#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

class Game: public QGraphicsPixmapItem{
public:
    Game();
    void load();

private:
    QGraphicsView* view = NULL;
};

#endif // GAME_H

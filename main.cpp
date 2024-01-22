#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game* game = new Game();
    game->load();

    return a.exec();
}

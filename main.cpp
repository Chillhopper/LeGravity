#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "MyRect.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();

    MyRect* player = new MyRect();
    player->setRect(0,0,100,100);


    //NEED THIS TO PRINT
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
    QGraphicsView* view = new QGraphicsView(scene);

    view->show();
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0, 0, 800, 600);
    player->setPos(view->width()/2, view->height() - player->rect().height());

    //spawn enemies
    QTimer* timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()) );

    return a.exec();
}

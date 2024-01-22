#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "MyRect.h"
#include <QApplication>
#include <QTimer>
#include "Game.h"

Game::Game(){

    //QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();

    MyRect* player = new MyRect();
    //player->setRect(0,0,100,100);


    //NEED THIS TO PRINT
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
    this->view = new QGraphicsView(scene);

    //this->view->show();
    this->view->setFixedSize(800, 600);
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QPixmap backgroundImage(":/Images/bg.png");
    this->view->setBackgroundBrush(QBrush(backgroundImage.scaled(view->size(), Qt::IgnoreAspectRatio)));

    scene->setSceneRect(0, 0, 800, 600);
    player->setPos(view->width()/2, view->height() - player->boundingRect().height());

    //spawn enemies
    QTimer* timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

    timer->start(2000);
}

void Game::load(){
    this->view->show();
}

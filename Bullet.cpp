#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"

Bullet::Bullet(){
    //setRect(0, 0, 10, 50);

    QPixmap originalPixmap(":/Images/bullet.png");
    int scaledWidth = 100; // Set the new width
    int scaledHeight = 100; // Set the new height
    QPixmap scaledPixmap = originalPixmap.scaled(scaledWidth, scaledHeight);
    setPixmap(QPixmap(scaledPixmap));

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move(){

    QList<QGraphicsItem *> list = collidingItems() ;
    for(int i = 0; i<list.size(); i++){
        Enemy* enemyCheck = dynamic_cast<Enemy*>(list[i]);
        if(enemyCheck){
            scene()->removeItem(list[i]);
            scene()->removeItem(this);

            delete list[i];
            delete this;

            return;
        }
    }


    setPos(x(), y()-10);
    if(pos().y() < -20){
        scene()->removeItem(this);
        delete this;
    }
}

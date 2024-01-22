#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy(){
    int rand_num = rand() % 700;

    QPixmap originalPixmap(":/Images/enemy.png");
    int scaledWidth = 400; // Set the new width
    int scaledHeight = 400; // Set the new height
    QPixmap scaledPixmap = originalPixmap.scaled(scaledWidth, scaledHeight);
    setPixmap(QPixmap(scaledPixmap));

    //setRect(0, 0, 30, 30);
    setPos(rand_num, -20);
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(), y()+5);
    if(pos().y() > scene()->height()){
        scene()->removeItem(this);
        delete this;
    }
}

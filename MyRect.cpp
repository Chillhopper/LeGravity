#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

MyRect::MyRect(){

    QPixmap originalPixmap(":/Images/player.png");
    int scaledWidth = 100; // Set the new width
    int scaledHeight = 100; // Set the new height
    QPixmap scaledPixmap = originalPixmap.scaled(scaledWidth, scaledHeight);
    setPixmap(QPixmap(scaledPixmap));

    setPos(100, 200);
}

void MyRect::keyPressEvent(QKeyEvent *event){


    if(event->key() == Qt::Key_A && x() > 0){
        setPos(x()-10, y());
    }else if(event->key() == Qt::Key_D && x()+100 < 800){
        setPos(x()+10, y());
    }else if(event->key() == Qt::Key_S){
        setPos(x(), y()+10);
    }else if(event->key() == Qt::Key_W){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        qDebug() << "Bullet created";
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }

}

void MyRect::spawn(){
    Enemy* spawnEnemy = new Enemy();
    scene()->addItem(spawnEnemy);
}

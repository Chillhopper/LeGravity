#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"

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
        bullet->setPos(x()+45, y());
        scene()->addItem(bullet);
    }
}

 #include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    int count = rand();

    if(count % 4 == 0){
        setPixmap(QPixmap(":/img/salman.png"));
    }else if(count % 4 == 1){
        setPixmap(QPixmap(":/img/karan.png"));
    }else if(count % 4 == 2){
        setPixmap(QPixmap(":/img/alia.png"));
    }else if(count % 4 == 3){
        setPixmap(QPixmap(":/img/karan.png"));
    }
    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

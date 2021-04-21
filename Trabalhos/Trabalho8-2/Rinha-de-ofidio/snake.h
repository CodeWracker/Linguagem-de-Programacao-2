#ifndef SNAKE_H
#define SNAKE_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

#include <iostream>

using namespace std;
class Snake : public QObject, public QGraphicsRectItem
{
    Q_OBJECT


private:
    QMediaPlayer *bulletsound;
    string lastMove;
public:
    void reset(){
        isVivo = true;
    }
    bool isVivo;
    Snake(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void move(string decisao);
    void die();
    bool ready;
public slots:
    void move(){
        move(lastMove);
    };

};


#endif // SNAKE_H

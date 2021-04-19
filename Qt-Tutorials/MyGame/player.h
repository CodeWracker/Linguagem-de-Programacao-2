#ifndef PLAYER_H
#define PLAYER_H
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

#include <QMediaPlayer>
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    bool isVivo = true;

private:
    QMediaPlayer *bulletsound;

public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
};
#endif // PLAYER_H

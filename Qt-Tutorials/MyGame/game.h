#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"

class GameEnv : public QGraphicsView

{
public:
      Game(QWidget *parent = 0);
      QGraphicsScene *scene;
      Player *player;
      Player *enemy;
      Score *score;
      Health *health;
      int state = {
            "Food" : [ 0, 1 ];
      "Player" : [ [ 1, 1 ], [ 1, 2 ] ],
                 "Enemy" : [ [ 0, 0 ], [ 1, 0 ] ]
}
}
;

#endif // GAME_H

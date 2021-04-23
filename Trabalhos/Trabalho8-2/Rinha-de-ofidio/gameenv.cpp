#include "gameenv.h"

#include <stdlib.h>
#include <QGraphicsTextItem>
#include <QMediaPlaylist>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>

#include <QKeyEvent>
void GameEnv::clean(){
    // criar scene
    //if(scene)
     scene = new QGraphicsScene();
     // fixar o tamanho em 800x600, que é infinito por definição
     scene->setSceneRect(0, 0, 704, 704);
     setScene(scene);
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     // fixar o tamanho
     setFixedSize(704, 704);
}
void GameEnv::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        // limite para não sair da tela
        player->move("Left");
    }
    else if (event->key() == Qt::Key_Right)
    {
        // limite para não sair da tela
        player->move("Right");
    }
    else if (event->key() == Qt::Key_Up)
    {
        player->move("Up");
    }
    else if (event->key() == Qt::Key_Down)
    {
        player->move("Down");
    }
}
GameEnv::GameEnv(QWidget *parent)
{

    ready = false;
    timer = new QTimer();
    clean();
    scene->setBackgroundBrush(QBrush(QImage("://images/GameBackground.png")));
    player = new Snake();
    enemy = new Snake();
    rodada = 0;
    tipo = { "Normal", "Normal", "Normal", "Boss" };
    state.food.push_back(new Food());
    state.food.push_back(new Food());
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::movePlayer,this,""));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::newGame,this,""));
    connect(timer, &QTimer::timeout, this, std::bind(&GameEnv::agent,this,state,inimigoAgent));
}
void GameEnv::newGame(string a){
    player->ready = ready;
    enemy->ready = ready;
    refresh();
    if((player->isVivo && !enemy->isVivo))
    {
        cout << "Novo Jogo"<<endl;
        /*delete player;
        delete enemy;
        delete state.food.at(0);
        delete state.food.at(1);
        player = new Snake("Player");
        enemy = new Snake(tipo.at(0));
        inimigoAgent = tipo.at(0);
        rodada++;
        ready = false;
        return;*/
    }
    if(!player->isVivo) {
        ready = false;
        timer->stop();
        hide();
        return;
    }
    QList<QGraphicsItem *> colliding_item_player = player->myBody.at(0)->collidingItems();
    QList<QGraphicsItem *> colliding_item_enemy = enemy->myBody.at(0)->collidingItems();

    for(int i = 0, n = colliding_item_player.size(); i < n; i++){
         for(size_t j = 0; j<state.food.size();j++)
         {
             Food* foo = state.food.at(j);
             if(colliding_item_player[i] == foo){
                 player->addNew();
                 delete state.food.at(j);
                 state.food.at(j) = new Food();

             }
         }
    }
    for(int i = 0, n = colliding_item_enemy.size(); i < n; i++){
         for(size_t j = 0; j<state.food.size();j++)
         {
             Food* foo = state.food.at(j);
             if(colliding_item_enemy[i] == foo){
                 enemy->addNew();
                 delete state.food.at(j);
                 state.food.at(j) = new Food();

             }
         }
    }
    refresh();

}
void GameEnv::refresh(){

    QList<QGraphicsItem *>  tel = scene->items();
    for(Food* foo : state.food){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(foo == i) achou = true;
        }
        if(!achou)
        scene->addItem(foo);
    }
    for(BodyPart* part: player->myBody){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(part == i) achou = true;
        }
        if(!achou)
        scene->addItem(part);
    }
    for(BodyPart* part: enemy->myBody){
        bool achou = false;
        for (QGraphicsItem* i : tel){
            if(part == i) achou = true;
        }
        if(!achou)
        scene->addItem(part);
    }
}
void GameEnv::gameExecution(int r){
    ready = false;

    rodada = r;
    delete player;
    delete enemy;
    player = new Snake("Player");
    inimigoAgent = tipo.at(0);
    enemy = new Snake(inimigoAgent);
    refresh();
    //clean();
    gameExecution();
}
void GameEnv::gameExecution()
{


     // adicionar o jogador no cenario
     // criar inimigos


     timer->start(250);

     //QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

     show();

}

// #include "gamescene.h"
// #include <QKeyEvent>
// #include <QInputDialog>
// #include <QMessageBox>

// GameScene::GameScene(QObject* parent)
//     : QGraphicsScene(parent)
// {
//     setSceneRect(0, 0, 800, 600);

//     player = new Player();
//     addItem(player);
//     player->setPos(50, 50);

//     // Load sound
//     gunshot = sound.loadWav("sounds/gunshot.wav");

//     spawnEnemies(5);
//     setupQuestions();

//     QTimer* timer = new QTimer(this);
//     connect(timer, &QTimer::timeout, this, &GameScene::updateFrame);
//     timer->start(30);
// }

// void GameScene::spawnEnemies(int count)
// {
//     for (int i = 0; i < count; i++)
//     {
//         Enemy* e = new Enemy();
//         e->setPos(rand()%700 + 50, rand()%500 + 50);
//         enemies.append(e);
//         addItem(e);
//     }
// }

// void GameScene::setupQuestions()
// {
//     QStringList qtext = {
//         "5 + 7 = ?",
//         "10 կամ 8, որն է մեծ?",
//         "Որ գույնն է երկինքը?"
//     };
//     QStringList ans = { "12", "10", "կապույտ" };

//     for (int i = 0; i < qtext.size(); i++)
//     {
//         auto* t = new QGraphicsTextItem("?");
//         t->setDefaultTextColor(Qt::magenta);
//         t->setScale(2);
//         t->setPos(100 + i*150, 300);
//         questionItems.append(t);
//         addItem(t);
//     }
// }

// void GameScene::keyPressEvent(QKeyEvent *event)
// {
//     if (event->key() == Qt::Key_Up)
//         player->setY(player->y() - 10),
//             player->direction = 0;

//     if (event->key() == Qt::Key_Right)
//         player->setX(player->x() + 10),
//             player->direction = 1;

//     if (event->key() == Qt::Key_Down)
//         player->setY(player->y() + 10),
//             player->direction = 2;

//     if (event->key() == Qt::Key_Left)
//         player->setX(player->x() - 10),
//             player->direction = 3;

//     if (event->key() == Qt::Key_Space)
//         fireBullet();

//     QGraphicsScene::keyPressEvent(event);
// }

// void GameScene::fireBullet()
// {
//     Bullet* b = new Bullet(player->direction);
//     b->setPos(player->pos());

//     addItem(b);

//     sound.play(gunshot);
// }

// void GameScene::updateFrame()
// {
//     advance();
// }

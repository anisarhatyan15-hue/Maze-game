// #ifndef GAMESCENE_H
// #define GAMESCENE_H

// #include <QGraphicsScene>
// #include <QTimer>

// #include "player.h"
// #include "bullet.h"
// #include "enemy.h"
// #include "openalengine.h"

// class GameScene : public QGraphicsScene
// {
//     Q_OBJECT

// public:
//     GameScene(QObject* parent = nullptr);

//     void spawnEnemies(int count);
//     void setupQuestions();
//     void fireBullet();

// protected:
//     void keyPressEvent(QKeyEvent* event) override;

// private slots:
//     void updateFrame();

// private:
//     Player* player;
//     QVector<Enemy*> enemies;
//     QVector<QGraphicsTextItem*> questionItems;

//     OpenALEngine sound;
//     ALuint gunshot;

//     bool questionsAnswered = false;
// };

// #endif

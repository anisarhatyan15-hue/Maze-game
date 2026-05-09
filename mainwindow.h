



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include <QKeyEvent>
#include <QInputDialog>
#include <QMessageBox>

struct Cell {
    bool top=true, bottom=true, left=true, right=true;
    bool visited=false;
};

struct Question {
    int row;
    int col;
    QString text;
    QString answer;
    bool answered=false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    const int rows = 10;
    const int cols = 15;
    const int cellSize = 40;

    QVector<QVector<Cell>> grid;

    int playerRow, playerCol;
    bool playerIsGirl;
    QColor playerColor;

    QString playerName;
    int lives;
    int score = 0;
    int level = 0;
    QColor bgColor = Qt::black;

    QVector<Question> questions;

    QTimer *timer;

    void askPlayerData();
    void resetMaze();
    void generateMazePrims();
    void removeWalls(Cell &c1, Cell &c2, int dir);
    void setupQuestions();
    void nextLevel();

    void drawPlayer(QPainter &p);
};

#endif // MAINWINDOW_H

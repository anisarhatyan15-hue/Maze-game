#include "mainwindow.h"
#include <QPainter>
#include <ctime>
#include <cstdlib>
#include <QtMath>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(cols * cellSize + 1, rows * cellSize + 1);

    grid.resize(rows);
    for (auto &r : grid) r.resize(cols);

    std::srand(std::time(nullptr));

    askPlayerData();
    resetMaze();

    lives = 3;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() { update(); });
    timer->start(100);
}

MainWindow::~MainWindow(){}

void MainWindow::askPlayerData()
{
    bool ok;
    playerName = QInputDialog::getText(
        this, "Տվյալներ", "Անուն Ազգանուն:", QLineEdit::Normal, "", &ok);

    QString gender = QInputDialog::getItem(
        this, "Սեռ", "Ընտրիր սեռը:", {"Տղա", "Աղջիկ"}, 0, false, &ok);

    playerIsGirl = (gender == "Աղջիկ");
    playerColor = playerIsGirl ? QColor(255,105,180) : QColor(255,230,0);

    playerRow = 0;
    playerCol = 0;
}

void MainWindow::resetMaze()
{
    for (auto &r : grid)
        for (auto &c : r)
            c = Cell();

    generateMazePrims();
    setupQuestions();

    bgColor = (level == 0 ? QColor(25,25,25)
               : level == 1 ? QColor(15,0,60)
                            : QColor(0,50,0));
}

void MainWindow::generateMazePrims()
{
    for(int r=0;r<rows;r++)
        for(int c=0;c<cols;c++)
            grid[r][c] = Cell();

    struct Wall { int r,c,nr,nc,dir; };
    QVector<Wall> walls;

    int r = rand()%rows;
    int c = rand()%cols;
    grid[r][c].visited = true;

    auto addWalls = [&](int r,int c){
        if(r>0 && !grid[r-1][c].visited) walls.push_back({r,c,r-1,c,0});
        if(c<cols-1 && !grid[r][c+1].visited) walls.push_back({r,c,r,c+1,1});
        if(r<rows-1 && !grid[r+1][c].visited) walls.push_back({r,c,r+1,c,2});
        if(c>0 && !grid[r][c-1].visited) walls.push_back({r,c,r,c-1,3});
    };

    addWalls(r,c);

    while(!walls.isEmpty()){
        int i = rand() % walls.size();
        Wall w = walls[i];
        walls.remove(i);

        if(!grid[w.nr][w.nc].visited){
            removeWalls(grid[w.r][w.c], grid[w.nr][w.nc], w.dir);
            grid[w.nr][w.nc].visited = true;
            addWalls(w.nr, w.nc);
        }
    }
}

void MainWindow::removeWalls(Cell &c1, Cell &c2, int dir)
{
    if(dir==0){ c1.top=false; c2.bottom=false; }
    if(dir==1){ c1.right=false; c2.left=false; }
    if(dir==2){ c1.bottom=false; c2.top=false; }
    if(dir==3){ c1.left=false; c2.right=false; }
}

void MainWindow::setupQuestions()
{
    questions.clear();

    if(level == 0){
        questions = {
            {2,2,"3+4=?", "7"},
            {5,6,"10-6=?", "4"}
        };
    }
    else if(level == 1){
        questions = {
            {3,4,"6*2=?", "12"},
            {7,1,"12/3=?", "4"}
        };
    }
    else {
        questions = {
            {4,3,"20-7=?", "13"},
            {2,8,"9+5=?", "14"}
        };
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.fillRect(rect(), bgColor);

    // Draw maze
    p.setPen(QPen(Qt::white, 2));
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            int x=c*cellSize, y=r*cellSize;
            auto &cell = grid[r][c];

            if(cell.top)    p.drawLine(x,y,x+cellSize,y);
            if(cell.bottom) p.drawLine(x,y+cellSize,x+cellSize,y+cellSize);
            if(cell.left)   p.drawLine(x,y,x,y+cellSize);
            if(cell.right)  p.drawLine(x+cellSize,y,x+cellSize,y+cellSize);
        }
    }

    // Animated portal
    int px = (cols-1)*cellSize + 5;
    int py = (rows-1)*cellSize + 5;
    int size = cellSize-10;
    double t = QDateTime::currentMSecsSinceEpoch()/200.0;
    int glow = 180 + int(50*qSin(t));
    QColor portalColor(glow,0,255);
    p.setBrush(portalColor);
    p.setPen(Qt::NoPen); // No white edges
    p.drawEllipse(px, py, size, size);

    // Draw questions
    p.setPen(Qt::cyan);
    p.setFont(QFont("Arial", 18, QFont::Bold));
    for(auto &q : questions){
        if(!q.answered){
            p.drawText(q.col*cellSize+12, q.row*cellSize+28, "?");
        }
    }

    // Draw player
    drawPlayer(p);

    // HUD: name & hearts
    p.setFont(QFont("Arial", 14, QFont::Bold));
    p.setPen(Qt::white);
    p.drawText(10, 20, "Player: " + playerName);

    QString hearts;
    for(int i=0; i<lives; ++i) hearts += "❤️";
    p.drawText(10, 40, hearts);
}

void MainWindow::drawPlayer(QPainter &p)
{
    int x = playerCol*cellSize + cellSize/2;
    int y = playerRow*cellSize + cellSize/2;

    p.setFont(QFont("Arial", 24));
    QString emoji = playerIsGirl ? "👧" : "👦";
    p.drawText(x-12, y+12, emoji);

    // Small walking sparkle effect
    p.setPen(QPen(QColor(255, 255, 0, 200)));
    p.setFont(QFont("Arial", 12));
    for(int i=0;i<2;i++){
        int sx = x + (rand()%21 - 10);
        int sy = y + (rand()%21 - 10);
        p.drawText(sx, sy, "✨");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int r = playerRow;
    int c = playerCol;

    auto &cell = grid[r][c];

    if(e->key()==Qt::Key_Up    && !cell.top)    r--;
    if(e->key()==Qt::Key_Down  && !cell.bottom) r++;
    if(e->key()==Qt::Key_Left  && !cell.left)   c--;
    if(e->key()==Qt::Key_Right && !cell.right)  c++;

    // Check questions
    for(auto &q : questions){
        if(q.row==r && q.col==c && !q.answered){
            bool ok;
            QString ans = QInputDialog::getText(
                this, "Հարց", q.text, QLineEdit::Normal,"",&ok);

            if(ans == q.answer){
                q.answered = true;
                score += 10;
            } else {
                lives--;
                if(lives<=0){
                    QMessageBox::information(this,"Խաղ ավարտվեց",
                                             "Դուք պարտվեցիք։ Միավորներ: "
                                                 +QString::number(score));
                    level = 0;
                    score = 0;
                    lives = 3;
                }
                playerRow = 0;
                playerCol = 0;
                return;
            }
        }
    }

    playerRow = r;
    playerCol = c;

    // Level complete
    if(playerRow==rows-1 && playerCol==cols-1)
        nextLevel();

    update();
}

void MainWindow::nextLevel()
{
    level++;
    if(level >= 3){
        QMessageBox::information(this,"Հաղթանակ",
                                 "Դուք անցաք բոլոր 3 փուլերը!\nՄիավորներ: "
                                     +QString::number(score));
        level = 0;
        score = 0;
        lives = 3;
    }

    playerRow = 0;
    playerCol = 0;
    resetMaze();
    update();
}

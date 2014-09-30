#include "scorewindow.h"
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>

ScoreWindow::ScoreWindow() : QWidget(0)
{
    topnum = 0;

    scoreScene = new QGraphicsScene(0,0,1024,768);
    scoreText = new QGraphicsTextItem();
    scorefont = scoreText->font();
    scorefont.setPointSize(300);
    scorefont.setBold(true);

    scoreText->setPlainText("Hello");
    scoreText->setPos(20,150);
    scoreText->setDefaultTextColor(Qt::yellow);
    scoreText->setFont(scorefont);

    userID = new QGraphicsTextItem();
    userIDfont = userID->font();
    userIDfont.setPointSize(70);

    userID->setPlainText("Guest");
    userID->setPos(100,20);
    userID->setDefaultTextColor(Qt::red);
    userID->setFont(userIDfont);

    topScore = new QGraphicsTextItem();
    topfont = topScore->font();
    topfont.setPointSize(50);
    topScore->setPlainText("topScore" + QString::number(topnum));
    topScore->setPos(400,600);
    topScore->setDefaultTextColor(Qt::green);
    topScore->setFont(topfont);


    scoreScene->addItem(userID);
    scoreScene->addItem(topScore);
    scoreScene->addItem(scoreText);

    QGraphicsView *scoreView = new QGraphicsView();
    scoreView->setScene(scoreScene);
    QVBoxLayout *scoreLayout = new QVBoxLayout();
    scoreLayout->addWidget(scoreView);
    setLayout(scoreLayout);
    //changeScore(133,20);
}
void ScoreWindow::changeScore(int score,int id){
    fprintf(stderr,"%d",score);
    scoreText->setPlainText(QString::number(score));
    if(id != 0){
        QString *comment = new QString("ID:" + QString::number(id) + "'s sore");
        userID->setPlainText(*comment);
    }
    if(score > topnum){
        topnum = score;
        updateTop();
    }
}

void ScoreWindow::updateTop(){
    topScore->setPlainText("topScore: " + QString::number(topnum));
    topImage = new QGraphicsPixmapItem(QPixmap(":/material/kangazou.png"));
    topImage->setPos(300,300);
    scoreScene->addItem(topImage);
    topDeleteTime = new QTimer(this);
    QObject::connect(topDeleteTime,SIGNAL(timeout()),this,SLOT(deleteTopImage()));
    topDeleteTime->start(1*2000);
}

void ScoreWindow::deleteTopImage(){
    scoreScene->removeItem(topImage);
    topDeleteTime->stop();
}

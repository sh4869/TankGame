#include "scorewindow.h"
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>

ScoreWindow::ScoreWindow()
{
    topnum = 0;

    scoreScene = new QGraphicsScene(0,0,800,600);
    scoreText = new QGraphicsTextItem();
    scorefont = scoreText->font();
    scorefont.setPointSize(100);
    scorefont.setBold(true);

    scoreText->setPlainText("Hello");
    scoreText->setPos(200,200);
    scoreText->setDefaultTextColor(Qt::yellow);
    scoreText->setFont(scorefont);

    userID = new QGraphicsTextItem();
    userID->setPlainText("Guest");
    userID->setPos(100,50);
    userID->setDefaultTextColor(Qt::red);
    userID->setFont(scorefont);

    topScore = new QGraphicsTextItem();
    topfont = topScore->font();
    topfont.setPointSize(50);
    topScore->setPlainText(QString::number(topnum));
    topScore->setPos(300,500);
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
    changeScore(100,12);
}
void ScoreWindow::changeScore(int score,int id){
    fprintf(stderr,"%d",score);
    scoreText->setPlainText(QString::number(score));
    if(id != 0){
        userID->setPlainText(QString::number(id));
    }
    if(score > topnum){
        topnum = score;
        updateTop();
    }
}

void ScoreWindow::updateTop(){
    topScore->setPlainText(QString::number(topnum));
}

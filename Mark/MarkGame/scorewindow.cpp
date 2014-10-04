#include "scorewindow.h"
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>

ScoreWindow::ScoreWindow() : QWidget(0)
{
    topnum = 0;
    nowScore = 0;
    scoreScene = new QGraphicsScene(0,0,1024,768);
    scoreText = new QGraphicsTextItem();
    scorefont = scoreText->font();
    scorefont.setPointSize(300);
    scorefont.setBold(true);

    scoreText->setPlainText("Hello");
    scoreText->setPos(20,150);
    scoreText->setDefaultTextColor(Qt::yellow);
    scoreText->setFont(scorefont);


    topScore = new QGraphicsTextItem();
    topfont = topScore->font();
    topfont.setPointSize(50);
    topScore->setPlainText("");
    topScore->setPos(400,600);
    topScore->setDefaultTextColor(Qt::green);
    topScore->setFont(topfont);


    scoreScene->addItem(topScore);
    scoreScene->addItem(scoreText);

    QGraphicsView *scoreView = new QGraphicsView();
    scoreView->setScene(scoreScene);
    QVBoxLayout *scoreLayout = new QVBoxLayout();
    scoreLayout->addWidget(scoreView);
    setLayout(scoreLayout);
    //changeScore(133,20);
}
void ScoreWindow::changeScore(int score){
    nowScore = score;
    fprintf(stderr,"%d",score);
    scoreText->setPlainText(QString::number(score));
}

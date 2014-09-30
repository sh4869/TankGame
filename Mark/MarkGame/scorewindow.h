#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QFont>

class ScoreWindow : public QWidget
{
public:
    ScoreWindow();
    QGraphicsScene *scoreScene;
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *userID;
    QGraphicsTextItem *topScore;
    QFont scorefont;
    QFont topfont;
    int topnum;
    void changeScore(int score,int id);
protected:
    void updateTop();
};

#endif // SCOREWINDOW_H

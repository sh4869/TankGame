#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QFont>

class ScoreWindow : public QWidget
{
    Q_OBJECT

public:
    ScoreWindow();
    QGraphicsScene *scoreScene;
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *userID;
    QGraphicsTextItem *topScore;
    QFont scorefont;
    QFont topfont;
    QFont userIDfont;

    QTimer *topDeleteTime;

    //Create update Top widget
    QGraphicsPixmapItem *topImage;
    void changeScore(int score);
    int topnum;

public slots:
    void deleteTopImage();

private:
    void updateTop();

protected:

};

#endif // SCOREWINDOW_H

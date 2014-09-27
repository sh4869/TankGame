#ifndef MARKGAME_H
#define MARKGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QLayout>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QThread>
#include <QtGui>
#include <QMediaPlayer>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MovableGraphicsPixmapItem.h"
#include "MarkgamePrivate.h"
#define JUN 6
#define TIME 30

class Markgame : public QWidget
{
  Q_OBJECT
  Q_DECLARE_PRIVATE(Markgame)

public:
  Markgame();
  ~Markgame();
  void gamefinish();
  QPropertyAnimation* createImageAnimation(MovableGraphicsPixmapItem* item,int duration,QPointF ImagePoint);
  MovableGraphicsPixmapItem* createImageItem(const QString& pixmapFileName);
  QGraphicsScene *graphicsScene;
  MovableGraphicsPixmapItem **ImageItem;
  QPointF B[JUN+1];
  QPropertyAnimation** ImageAnimation;
  QGraphicsTextItem *pointtext;
  QGraphicsTextItem *timecount;
  QGraphicsTextItem *tellfinish;
  QGraphicsTextItem *starttext;
  QTimer *timer;
  QTimer *starttimer;
  QTimer *waittime;
  QTimer *deletetimer;
  QFont font;
  QMediaPlayer *player;
  QString strscore;

protected:
   void keyPressEvent(QKeyEvent *);

private:
  MarkgamePrivate* d_ptr;
  int I[JUN+1],ch[JUN+1],pointsu[100];
  int i,loop,leavetime,point_amount,score;
  FILE *fp;
  char pointloc[5],pointlocpre[5],pointmoji[100];
  char leavetimemoji[3];
  //QString *strscore;

private slots:
  void startAnimation();
  void updatetime();
  void hitBall(int marknum);
  void scoreCalcution(int number);
  void newgame();
  void startgame();
  void startTime();
  void removetext();

signals:
  void quit();
  void updateuserpoint(int user_point_amount);
};

#endif // MARKGAME_H

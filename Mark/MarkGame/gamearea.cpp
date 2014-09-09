#include "gamearea.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <QPainter>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
  points[0]=QPointF(10,10);
  points[1]=QPointF(200,10);
  points[2]=QPointF(400,10);
  points[3]=QPointF(10,300);
  points[4]=QPointF(200,300);
  points[5]=QPointF(400,300);

  QTimer *reload = new QTimer();
  connect(reload,SIGNAL(timeout()),SLOT(reloadAnimation()));
  reload->start(1*2000);
  kan.load(":/images/kan.png");
  taoreta.load(":/images/taoreta.png");
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

QSize GameArea::minimumSizeHint() const
{
  return QSize(100,100);
}

QSize GameArea::sizeHint() const
{
  return QSize(700,600);
}
void GameArea::reloadAnimation(){
  printf("update\n");
  update();
}

void GameArea::paintEvent(QPaintEvent *event)
{

  srand((unsigned)time(NULL));
  pointnum = rand()%6;
  QPainter painter(this);
  painter.drawPixmap(points[pointnum],kan);
}


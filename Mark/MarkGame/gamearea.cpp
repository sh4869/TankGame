#include "gamearea.h"
#include <stdlib.h>
#include <time.h>

#include <QPainter>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
  pixmap.load(":/images/kan.png");
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

QSize GameArea::minimumSizeHint() const
{
  return QSize(100,100);
}

QSize GameArea::sizeHint() const
{
  return QSize(1000,600);
}

void GameArea::paintEvent(QPaintEvent *event)
{
  static const QPointF points[6] = {
	QPointF(10,10),
	QPointF(200,10),
	QPointF(400,10),
	QPointF(10,300),
	QPointF(200,300),
	QPointF(400,300)
  };

  srand((unsigned)time(NULL));

  QPainter painter(this);
  painter.drawPixmap(points[rand()%6],pixmap);
}

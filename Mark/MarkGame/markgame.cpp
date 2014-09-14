#include "markgame.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include <QPainter>

MarkGame::MarkGame() : QWidget(0),d_ptr(new MarkGamePrivate)
{
  Q_D(MarkGame);
  graphicsScene = new QGraphicsScene(0,0,d->movingAreaSize.width(),d->movingAreaSize.height());

  // Point text
  pointtext = new QGraphicsTextItem();
  font = pointtext->font();
  font.setPointSize(72);
  font.setBold(true);
  pointtext->setPos(100,50);
  pointtext->setPlainText("Hello");
  pointtext->setDefaultTextColor(Qt::red);
  pointtext->setFont(font);
  timecount = new QGraphicsTextItem();
  timecount->setPos(700,50);
  timecount->setPlainText("Time");
  timecount->setDefaultTextColor(Qt::green);
  timecount->setFont(font);
  graphicsScene->addItem(pointtext);
  graphicsScene->addItem(timecount);
  
  QGraphicsView* view = new QGraphicsView();
  view->setScene(graphicsScene);
  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(view);
  setLayout(layout);
}


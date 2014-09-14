#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "markgamePrivate.h"


class MarkGame : public QWidget{
  Q_OBJECT
  Q_DECLARE_PRIVATE(MarkGame)

  public:
	MarkGame();
	QGraphicsScene *graphicsScene;
	QGraphicsTextItem *pointtext;
	QGraphicsTextItem *timecount;
	QTimer *timer;
	QFont font;

  private:
	QPixmap pixmap;
	MarkGamePrivate* d_ptr;
};

#endif

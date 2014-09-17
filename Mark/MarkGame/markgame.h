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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "markgamePrivate.h"
#define TIME 60


class MarkGame : public QWidget{
  Q_OBJECT
  Q_DECLARE_PRIVATE(MarkGame)

  public:
	MarkGame();
    void gamefinish();
	QGraphicsScene *graphicsScene;
	QGraphicsPixmapItem **imageItem;
	QGraphicsTextItem *timecount;
	QPixmap *imagedata;
	QPointF *point;
	QTimer *timer;
	QFont font;

  private:
	QPixmap pixmap;
	MarkGamePrivate* d_ptr;
    
	char leavetimemoji[3];
    int i;
	int leavetime,leavetimecpy;


  private slots:
	void updatetime();
  signals:
    void quit();

};

#endif

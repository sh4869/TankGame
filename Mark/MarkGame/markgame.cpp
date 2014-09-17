#include "markgame.h"
#include "score.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include <QPainter>

MarkGame::MarkGame() : QWidget(0),d_ptr(new MarkGamePrivate)
{
  Q_D(MarkGame);
  graphicsScene = new QGraphicsScene(0,0,d->movingAreaSize.width(),d->movingAreaSize.height());
  point = new QPointF[3];
  point[0]=QPointF(200,200);
  point[1]=QPointF(400,200);
  point[2]=QPointF(600,200);
  imagedata = new QPixmap(":images/kan.png");

  imageItem = new QGraphicsPixmapItem*[3];
  	imageItem[1]->setPixmap(*imagedata);
  	imageItem[1]->setPos(point[0]);
	printf("1\n");
	imageItem[2]->setPixmap(*imagedata);
	imageItem[2]->setPos(point[1]);
	imageItem[0]->setPixmap(*imagedata);
	imageItem[0]->setPos(point[2]);
	printf("test\n");
  for(i=0;i<3;i++){
  	graphicsScene->addItem(imageItem[i]);
  }


  // Point text
  timecount = new QGraphicsTextItem();
  font = timecount->font();
  font.setPointSize(72);
  font.setBold(true);
  timecount->setPos(700,50);
  timecount->setPlainText("Time");
  timecount->setDefaultTextColor(Qt::green);
  timecount->setFont(font);
  graphicsScene->addItem(timecount);

  QGraphicsView* view = new QGraphicsView();
  view->setScene(graphicsScene);
  QVBoxLayout* layout = new QVBoxLayout;
  layout->addWidget(view);
  setLayout(layout);

  timer = new QTimer(this);
  QObject::connect(timer,SIGNAL(timeout()),SLOT(updatetime()));
  timer->start(1*1000);

  i = 0;
  leavetime = TIME;
}

void MarkGame::gamefinish(){
  timer->stop();
  QGraphicsTextItem *tellfinish = new QGraphicsTextItem();
  font = timecount->font();
  font.setPointSize(100);
  font.setBold(true);
  tellfinish->setPos(100,300);
  tellfinish->setPlainText("GAME FINISH");
  tellfinish->setDefaultTextColor(Qt::red);
  tellfinish->setFont(font);
  graphicsScene->addItem(tellfinish);
}

void MarkGame::updatetime(){
  int j,timeketa=keta(leavetime),timepre,leavetimecpy;

  if(leavetime != 0){
	leavetimecpy = leavetime;
	for(j=0;j<sizeof(leavetimemoji);j++) leavetimemoji[j] = NULL;
	for(j=0;j<timeketa;j++){
	  leavetimemoji[j] = (leavetimecpy/jou(timeketa-j-1))+'0';
	  timepre = leavetimemoji[j]-'0';
	  leavetimecpy = leavetimecpy-timepre*jou(timeketa-j-1);
	  // fprintf(stderr,"timemoji = %c \n",leavetimemoji[j]);
	}
  }else{
	for(j=0;j<sizeof(leavetimemoji);j++) leavetimemoji[j]=NULL;
	leavetimemoji[0]=0+'0';
  }
  timecount->setPlainText(leavetimemoji);
  if(leavetime == 0) gamefinish();
  leavetime--;

}


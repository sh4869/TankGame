#include "markgame.h"
#include "score.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <QKeyEvent>
#include <QUrl>

Markgame::Markgame()
  : QWidget(0),d_ptr(new MarkgamePrivate)
{
  Q_D(Markgame);
  graphicsScene = new QGraphicsScene(0,0,d->movingAreaSize.width(), d->movingAreaSize.height());

  B[0]=QPointF(200,200);
  B[1]=QPointF(700,200);
  B[2]=QPointF(1200,200);
  B[3]=QPointF(200,600);
  B[4]=QPointF(700,600);
  B[5]=QPointF(1200,600);

  ImageItem = new MovableGraphicsPixmapItem*[JUN+1];
  ImageItem[0] = createImageItem(":/picture/1.jpg");
  ImageItem[1] = createImageItem(":/picture/2.jpg");
  ImageItem[2] = createImageItem(":/picture/3.jpg");
  ImageItem[3] = createImageItem(":/picture/4.jpg");
  ImageItem[4] = createImageItem(":/picture/5.jpg");
  ImageItem[5] = createImageItem(":/picture/6.jpg");

  pointtext=new QGraphicsTextItem();
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

  for(i=0;i<JUN;i++){
    ImageItem[i]->setPos(B[i]);
    graphicsScene->addItem(ImageItem[i]);
  }

  QGraphicsView* graphicsView = new QGraphicsView();
  graphicsView->setScene(graphicsScene);
  graphicsView->setBackgroundBrush(QPixmap(":/picture/back.jpg"));
  QVBoxLayout* topLayout = new QVBoxLayout;
  topLayout->addWidget(graphicsView);
  setLayout(topLayout);


  d->ImageAnimationGroup = new QParallelAnimationGroup(this);
  ImageAnimation = new QPropertyAnimation*[JUN+1];
  for(i=0;i<6;i++){
    ImageAnimation[i] = createImageAnimation(ImageItem[i],1*500,B[i]);
    d->ImageAnimationGroup->addAnimation(ImageAnimation[i]);
  }

  timer = new QTimer(this);
  QObject::connect(timer,SIGNAL(timeout()),SLOT(updatetime()));
  timer->start(1*1000);

  i=0;
  leavetime=TIME;
  for(loop=0;loop<JUN;loop++) I[loop]=0;

}

Markgame::~Markgame()
{
  delete d_ptr;
}

void Markgame::gamefinish()
{
  timer->stop();
  QGraphicsTextItem *tellfinish = new QGraphicsTextItem();
  font = pointtext->font();
  font.setPointSize(150);
  font.setBold(true);
  tellfinish->setPos(100,300);
  tellfinish->setPlainText("GAME FINISH");
  tellfinish->setDefaultTextColor(Qt::red);
  tellfinish->setFont(font);
  graphicsScene->addItem(tellfinish);
  fprintf(stderr,"gamefinish\n");
}

void Markgame::hitBall(){
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/sh4869/Documents/MicomClub/micomtanks/Mark/MarkGame/material/bakuhatu.wav"));
    player->setVolume(50);
    player->play();
    waittime = new QTimer(this);
    QObject::connect(waittime,SIGNAL(timeout()),SLOT(startAnimation()));
    waittime->start(2*1000);
}


void Markgame::startAnimation()
{
  Q_D(Markgame);
  int ranp,j,pre,pointpre,pointchpre,ketasu;
  srand((unsigned) time(NULL));

  for(loop=0;loop<JUN;loop++){
    if(I[loop]>0) ImageAnimation[ch[loop]]->setStartValue(B[loop]);
    if(I[loop]==0) I[loop]=1;
  }

  ranp = SixRandPos(rand()%720);
  pre = ranp;
  for(j=0;j<JUN;j++){
    ch[j]=(pre/jou(JUN-j-1))-1;
    pre=pre-(ch[j]+1)*jou(JUN-j-1);
    fprintf(stderr,"%d",ch[j]+1);
  }
  fprintf(stderr,"\n");
  for(loop=0;loop<JUN;loop++){
    ImageAnimation[ch[loop]]->setEndValue(B[loop]);
  }

  d->ImageAnimationGroup->start();

}

void Markgame::updatetime(){
  int j,timeketa=keta(leavetime),timepre,leavetimecpy;

  if(leavetime!=0){
    leavetimecpy=leavetime;
    for(j=0;j<sizeof(leavetimemoji);j++) leavetimemoji[j]=NULL;
    for(j=0;j<timeketa;j++){
      leavetimemoji[j]=(leavetimecpy/jou(timeketa-j-1))+'0';
      timepre=leavetimemoji[j]-'0';
      leavetimecpy=leavetimecpy-timepre*jou(timeketa-j-1);
      fprintf(stderr,"timemoji = %c \n",leavetimemoji[j]);
    }
  }else{
    for(j=0;j<sizeof(leavetimemoji);j++) leavetimemoji[j]=NULL;
    leavetimemoji[0]=0+'0';
  }
  timecount->setPlainText(leavetimemoji);
  if(leavetime==0) gamefinish();
  leavetime--;

}

MovableGraphicsPixmapItem* Markgame::createImageItem(const QString& pixmapFileName)
{
  MovableGraphicsPixmapItem* item = new MovableGraphicsPixmapItem(QPixmap(pixmapFileName));
  return item;
}

QPropertyAnimation* Markgame::createImageAnimation( MovableGraphicsPixmapItem* item,int duration,QPointF ImagePoint)
{
  QPropertyAnimation* imageAnimation = new QPropertyAnimation(item,"pos",this);
  imageAnimation->setEasingCurve(QEasingCurve::OutBounce);
  imageAnimation->setDuration(duration);
  imageAnimation->setStartValue(ImagePoint);
  return imageAnimation;
}
void Markgame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())  {
        case Qt::Key_1:
            hitBall();
            break;
        case Qt::Key_2:
            startAnimation();
            break;
        case Qt::Key_3:
            startAnimation();
            break;
        case Qt::Key_4:
            startAnimation();
            break;
        case Qt::Key_5:
            startAnimation();
            break;
        case Qt::Key_6:
            startAnimation();
            break;
        default:
            break;
    }
}


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

    B[0]=QPointF(150,200);
    B[1]=QPointF(450,200);
    B[2]=QPointF(750,200);
    B[3]=QPointF(150,500);
    B[4]=QPointF(450,500);
    B[5]=QPointF(750,500);

    ImageItem = new MovableGraphicsPixmapItem*[JUN+1];
    ImageItem[0] = createImageItem(":/material/kangazou.png");
    ImageItem[1] = createImageItem(":/material/kangazou.png");
    ImageItem[2] = createImageItem(":/material/kangazou.png");
    ImageItem[3] = createImageItem(":/material/kansilver.png");
    ImageItem[4] = createImageItem(":/material/kanking.png");
    ImageItem[5] = createImageItem(":/material/kandokuro.png");

    pointtext = new QGraphicsTextItem();
    font = pointtext->font();
    font.setPointSize(72);
    font.setBold(true);
    pointtext->setPos(100,50);
    pointtext->setPlainText("0");
    pointtext->setDefaultTextColor(Qt::red);
    pointtext->setFont(font);

    timecount = new QGraphicsTextItem();
    timecount->setPos(700,50);
    timecount->setPlainText("60");
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
    // timer->start(1*1000);
    i=0;
    score = 0;
    pointAddAble = false;
    leavetime=TIME;
    for(loop=0;loop<JUN;loop++) I[loop]=0;
    for(loop=1;loop<JUN+1;loop++) ch[loop] =loop;
}

Markgame::~Markgame()
{
    delete d_ptr;
}
void Markgame::startgame(){
    starttext = new QGraphicsTextItem();
    font = starttext->font();
    font.setPointSize(150);
    font.setBold(true);
    starttext->setPos(300,300);
    starttext->setPlainText("Ready?");
    starttext->setDefaultTextColor(Qt::blue);
    starttext->setFont(font);
    graphicsScene->addItem(starttext);
    starttimer = new QTimer;
    QObject::connect(starttimer,SIGNAL(timeout()),SLOT(startTime()));
    starttimer->start(3*1000);
}

void Markgame::startTime(){
    pointAddAble = true;
    starttimer->stop();
    starttext->setPlainText("Go!");
    timer->start(1*1000);
    deletetimer = new QTimer;
    QObject::connect(deletetimer,SIGNAL(timeout()),SLOT(removetext()));
    deletetimer->start(1*500);
}

void Markgame::removetext(){
    graphicsScene->removeItem(starttext);
    deletetimer->stop();
}

void Markgame::gamefinish()
{
    timer->stop();
    tellfinish = new QGraphicsTextItem();
    font = pointtext->font();
    font.setPointSize(100);
    font.setBold(true);
    tellfinish->setPos(100,300);//100 300
    tellfinish->setPlainText("GAME FINISH");
    tellfinish->setDefaultTextColor(Qt::red);
    tellfinish->setFont(font);
    graphicsScene->addItem(tellfinish);
    fprintf(stderr,"gamefinish\n");
    finishTimer = new QTimer();
    QObject::connect(finishTimer,SIGNAL(timeout()),this,SLOT(moveToScore()));
    finishTimer->start(1*5000);
}

void Markgame::moveToScore(){
    finishTimer->stop();
    emit finishGame();
}

void Markgame::hitBall(int marknum){
    scoreCalcution(marknum);
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:///material/bakuhatu.wav"));
    player->setVolume(80);
    player->play();
}

void Markgame::scoreCalcution(int number){
    if(pointAddAble == true){
        switch(ch[number-1] +1){
        case 1:
        case 2:
        case 3:
            score += 200;
            break;
        case 4:
            score += 300;
            break;
        case 5:
            score += 500;
            break;
        case 6:
            score -= 400;
            break;
        default:
            break;

        }
        fprintf(stderr,"%d\n",ch[number]);
        if(score < 0) score = 0;
        //fprintf(stderr,"%d\n",score);
        strscore = QString::number(score);
        pointtext->setPlainText(strscore);
        startAnimation();
    }
}

void Markgame::startAnimation()
{
    Q_D(Markgame);
    //waittime->stop();
    int ranp,j,pre,pointpre,pointchpre,ketasu;
    srand((unsigned) time(NULL));

    for(loop=0;loop<JUN;loop++){
        if(I[loop]>0) ImageAnimation[ch[loop]]->setStartValue(B[loop]);
        if(I[loop]==0) I[loop]=1;
    }

    // Create Rundom Six Figures for Place
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
    pointAddAble = false;
    d->ImageAnimationGroup->start();
    QObject::connect(d->ImageAnimationGroup,SIGNAL(finished()),this,SLOT(restartPointAdd()));
}
void Markgame::restartPointAdd(){
    pointAddAble = true;
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
        }
    }else{
        for(j=0;j<sizeof(leavetimemoji);j++) leavetimemoji[j]=NULL;
        leavetimemoji[0]=0+'0';
    }
    timecount->setPlainText(leavetimemoji);
    if(leavetime==0) gamefinish();
    leavetime--;

}

void Markgame::gameRestart(){
    timer->stop();
    leavetime=TIME;
    score=0;
    timecount->setPlainText("60");
    pointtext->setPlainText("0");
    graphicsScene->removeItem(tellfinish);
    startgame();
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

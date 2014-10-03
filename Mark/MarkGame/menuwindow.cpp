#include "menuwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLayout>
#include <QKeyEvent>
#include <QtWidgets>
#include <QDebug>

MenuWindow::MenuWindow() : QWidget(0)
{

    keymode = NOMKEY;
    ver = 0;
    idNum = 0;
    ableInput = true;
    menuScene = new QGraphicsScene(0,0,1024,768);

    inputidStr = new QGraphicsTextItem();

    idfont = inputidStr->font();
    idfont.setPointSize(60);
    idfont.setBold(true);
    inputidStr->setPos(100,300);
    inputidStr->setPlainText("");
    inputidStr->setDefaultTextColor(Qt::blue);
    inputidStr->setFont(idfont);

    menuScene->addItem(inputidStr);
    QGraphicsView *menuView = new QGraphicsView();
    menuView->setScene(menuScene);
    QVBoxLayout *menuLayout = new QVBoxLayout();
    menuLayout->addWidget(menuView);
    setLayout(menuLayout);
}

void MenuWindow::resetMenu(){
    idNum = 0;
    ver = 0;
    inputidStr->setPlainText("");
    idStr = "";
    ableInput = true;
}

void MenuWindow::addLoginNum(int num){
    if(num == -1){
        idStr = "";
        inputidStr->setPlainText(idStr);
        ver = 0;
        ableInput = true;
    }else{
        if(ver > 5){
            ableInput = false;
        }
        if(ableInput == true){
            idStr += QString::number(num);
            idNums[ver] = num;
            inputidStr->setPlainText(idStr);
            ver++;
        }else{
            /* beep warning music */
        }
    }
}

bool MenuWindow::idCheck(){
    int i,checkNum = 0;
    for(i=0;i<5;i++){
        checkNum += idNums[i];
    }
    if(checkNum / 7 == idNums[5]) return true;
    return false;
}


void MenuWindow::skipAllow(){
    keymode = SKIPKEY;
    skipAllowImage = new QGraphicsPixmapItem(QPixmap(":/material/kanking.png"));
    skipAllowImage->setPos(200,200);
    menuScene->addItem(skipAllowImage);
    ver = 0;
    idStr = "";
    inputidStr->setPlainText(idStr);
};

void MenuWindow::skipCheck(bool check){
    menuScene->removeItem(skipAllowImage);
    keymode = NOMKEY;
    if(check == true){
        emit startGame();
        fprintf(stderr,"skip Allow\n");
    }else{
        fprintf(stderr,"Don't skip\n");
        ableInput = true;
    }
};

void MenuWindow::idLogin(){
    if(ver == 6){
        if(idCheck() == true){
            idNum = idStr.toInt();
            emit startGame();
            fprintf(stderr,"OK\n");
        }else{
            fprintf(stderr,"Bad\n");
            int loop;
            for(loop=0;loop<6;loop++) idNums[loop] = 0;
            idStr = "";
            inputidStr->setPlainText(idStr);
            errorImage = new QGraphicsPixmapItem(QPixmap(":/material/kandokuro.png"));
            errorImage->setPos(200,200);
            menuScene->addItem(errorImage);
            errorDeleteTimer = new QTimer(this);
            QObject::connect(errorDeleteTimer,SIGNAL(timeout()),SLOT(errorDelete()));
            errorDeleteTimer->start(1*2000);
            ver =  0;
            ableInput = true;
        }
    }
}

void MenuWindow::errorDelete(){
    menuScene->removeItem(errorImage);
    errorDeleteTimer->stop();
}

void MenuWindow::keyPressEvent(QKeyEvent *event){
    if(keymode == SKIPKEY){
        if(event->key() == Qt::Key_Enter){
            skipCheck(true);
        }else if(event->key() == Qt::Key_Backspace){
            skipCheck(false);
        }
    }
    else{
        switch(event->key()){
        case Qt::Key_Plus:
            skipAllow();
            break;
        case Qt::Key_0:
            addLoginNum(0);
            break;
        case Qt::Key_1:
            addLoginNum(1);
            break;
        case Qt::Key_2:
            addLoginNum(2);
            break;
        case Qt::Key_3:
            addLoginNum(3);
            break;
        case Qt::Key_4:
            addLoginNum(4);
            break;
        case Qt::Key_5:
            addLoginNum(5);
            break;
        case Qt::Key_6:
            addLoginNum(6);
            break;
        case Qt::Key_7:
            addLoginNum(7);
            break;
        case Qt::Key_8:
            addLoginNum(8);
            break;
        case Qt::Key_9:
            addLoginNum(9);
            break;
        case Qt::Key_Backspace:
            addLoginNum(-1);
            break;
        case Qt::Key_Enter:
            fprintf(stderr,"Enter\n");
            idLogin();
            break;

        }
    }
}

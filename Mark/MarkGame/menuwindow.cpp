#include "menuwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLayout>
#include <QKeyEvent>

MenuWindow::MenuWindow()
{

    keymode = NOMKEY;
    ver = 0;
    menuScene = new QGraphicsScene(0,0,1024,768);

    inputidStr = new QGraphicsTextItem();

    idfont = inputidStr->font();
    idfont.setPointSize(60);
    idfont.setBold(true);
    inputidStr->setPos(100,300);
    inputidStr->setPlainText("Please Input Your ID!");
    inputidStr->setDefaultTextColor(Qt::blue);
    inputidStr->setFont(idfont);

    menuScene->addItem(inputidStr);
    QGraphicsView *menuView = new QGraphicsView();
    menuView->setScene(menuScene);
    QVBoxLayout *menuLayout = new QVBoxLayout();
    menuLayout->addWidget(menuView);
    setLayout(menuLayout);
}

void MenuWindow::addLoginNum(int num){
    if(num == -1){
        ver--;
        idStr = idStr.left(ver-1);
        inputidStr->setPlainText(idStr);
        if(ver < 5){
            ableInput = true;
        }
        if(ver < 1){
            ver = 0;
        }
    }else if(ableInput == true){
        idStr += QString::number(num);
        idNums[ver] = num;
        inputidStr->setPlainText(idStr);
        ver++;
        if(ver > 5){
            ableInput = false;
        }
    }else{
        /* beep warning music */
    }
}

bool MenuWindow::idLogincheck(int id){

}

void MenuWindow::skipAllow(){};
void MenuWindow::skipCheck(bool check){};
void MenuWindow::idLogin(){};
void MenuWindow::startGame(){};


void MenuWindow::keyPressEvent(QKeyEvent *event){
    if(keymode == SKIPKEY){
        if(event->key() == Qt::Key_Enter){
            skipCheck(true);
        }else if(event->key() == Qt::Key_Backspace){

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


        }
    }
}

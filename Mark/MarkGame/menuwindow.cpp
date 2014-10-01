#include "menuwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLayout>
#include <QKeyEvent>

MenuWindow::MenuWindow()
{
    idNum = 0;
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

}

bool MenuWindow::idLogincheck(int id){

}

void MenuWindow::skipAllow(){};
void MenuWindow::skipCheck(bool check){};
void MenuWindow::idLogin(){};
void MenuWindow::startGame(){};


void MenuWindow::keyPressEvent(QKeyEvent *event){
    if(keyMode == SKIPKEY){
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

        }
    }
}

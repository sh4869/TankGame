#include "menuwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLayout>

MenuWindow::MenuWindow()
{
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



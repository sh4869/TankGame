#ifndef MENU_H
#define MENU_H

#include <QtWidgets>
#include <QtGui>
#include <QGraphicsView>

class Menu : public QWidget
{
public:
    Menu();
    QGraphicsScene *scene;
    QGraphicsTextItem *inputID;

    QSize sizeHint() const;


private:
    QPushButton *passbutton;


};

#endif // MENU_H

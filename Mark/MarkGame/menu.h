#ifndef MENU_H
#define MENU_H

#include <QtWidgets>
#include <QtGui>

class Menu : public QWidget
{
public:
    Menu();
    QLineEdit *input;
    QSize sizeHint() const;


private:
    QPushButton *passbutton;


};

#endif // MENU_H

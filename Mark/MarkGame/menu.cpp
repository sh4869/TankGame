#include "menu.h"
#include <QtGui>
#include <QLayout>

Menu::Menu()
{
    input = new QLineEdit;
    //input->resize(50,100);

    passbutton = new QPushButton(tr("Test"));
    //passbutton->sizeHint(50,10);

    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->addWidget(input,3,0);
   // mainlayout->addWidget(passbutton,4,1,5,4);
    setLayout(mainlayout);
}

QSize Menu::sizeHint() const
{
    return QSize(400,300);
}

#include "gamearea.h"
#include "window.h"

#include <QtWidgets>

Window::Window()
 {
   gameArea = new GameArea;

   QGridLayout *mainLayout = new QGridLayout;

   mainLayout->addWidget(gameArea,0,0,1,4);
   setLayout(mainLayout);
 }

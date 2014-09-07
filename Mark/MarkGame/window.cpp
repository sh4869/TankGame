#include "window.h"

#include <QtWidgets>

Window::Window()
 {
   testLabel = new QLabel(tr("Test"));
   
   QGridLayout *mainLayout = new QGridLayout;

   mainLayout->addWidget(testLabel,0,0);
   setLayout(mainLayout);
 }

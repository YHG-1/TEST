#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <string>
#include <tchar.h>

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv ); 
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
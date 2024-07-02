#include "mechanical.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mechanical w;
    w.show();

    return a.exec();
}

#include "clock2024.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clock2024 w;
    w.show();

    return a.exec();
}

#include "twnlt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    twnlt w;
    w.show();
    return a.exec();
}

#include "qtpluginfinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtPluginFinder w;
    w.show();

    return a.exec();
}

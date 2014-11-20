#include <QCoreApplication>
#include "C:\Program Files (x86)\Intel\Composer XE 2015\ipp\include\ippcore.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ippInit();

    return a.exec();
}

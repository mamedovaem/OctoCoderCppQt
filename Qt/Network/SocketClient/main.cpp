#include <QCoreApplication>
#include "MyClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyClient client("localhost", 2323);

    return a.exec();
}

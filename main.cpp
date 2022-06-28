#include "StarCatalogue.h"
#include <QtWidgets/QApplication>
#include "Service.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Stars stars;
    Astronomers astronomers;
    Service serv{ astronomers, stars };

    StarCatalogue w{serv};
    return a.exec();
}

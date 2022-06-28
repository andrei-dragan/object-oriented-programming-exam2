#include "StarCatalogue.h"

StarCatalogue::StarCatalogue(Service& _serv, QWidget *parent)
    : serv{ _serv }, QMainWindow(parent)
{
    ui.setupUi(this);

    AstronomerModel* model = new AstronomerModel{ this->serv };

    for (auto astronomer : this->serv.getAstronomers()) {
        AstronomerWindow* w = new AstronomerWindow{ astronomer.getName(), astronomer.getConstellation(), model };
        w->setWindowTitle(QString::fromStdString(astronomer.getName()));
        w->show();
    }
}

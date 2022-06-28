#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StarCatalogue.h"
#include "Service.h"
#include "AstronomerModel.h"
#include "AstronomerWindow.h"

class StarCatalogue : public QMainWindow
{
    Q_OBJECT

public:
    StarCatalogue(Service& _serv, QWidget *parent = Q_NULLPTR);

private:
    Service& serv;
    Ui::StarCatalogueClass ui;
};

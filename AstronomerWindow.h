#pragma once

#include <QWidget>
#include "ui_AstronomerWindow.h"
#include "AstronomerModel.h"
#include "ConstellationWindow.h"

class AstronomerWindow : public QWidget
{
	Q_OBJECT

public:
	AstronomerWindow(std::string _name, std::string _constellation, AstronomerModel* _model, QWidget *parent = Q_NULLPTR);
	~AstronomerWindow();

private:
	std::string name;
	std::string constellation;
	AstronomerModel* model;
	Ui::AstronomerWindow ui;

public:
	void filterStars();
	void addStar();
	void updateStar();
	void drawConstellation();
};

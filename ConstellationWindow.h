#pragma once

#include <QWidget>
#include "ui_ConstellationWindow.h"
#include "Service.h"

class ConstellationWindow : public QWidget
{
	Q_OBJECT

public:
	ConstellationWindow(Service& _serv, std::string _constellation, std::string _star, QWidget *parent = Q_NULLPTR);
	~ConstellationWindow();
	void paintEvent(QPaintEvent* event);

private:
	Service& serv;
	std::string constellation, star;
	Ui::ConstellationWindow ui;
};

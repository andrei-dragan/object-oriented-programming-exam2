#include "ConstellationWindow.h"
#include <QPainter>

ConstellationWindow::ConstellationWindow(Service& _serv, std::string _constellation, std::string _star, QWidget *parent)
	: serv{ _serv }, constellation{ _constellation }, star{ _star }, QWidget(parent)
{
	ui.setupUi(this);
}

ConstellationWindow::~ConstellationWindow()
{
}

void ConstellationWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    for (auto star : this->serv.getStars()) {
        if (star.getConstellation() == this->constellation) {
            if (star.getName() != this->star) {
                painter.setPen(Qt::black);
                painter.drawEllipse(star.getRA(), star.getDec(), star.getDiameter() / 10, star.getDiameter() / 10);
            }
            else {
                painter.setPen(Qt::red);
                painter.drawEllipse(star.getRA(), star.getDec(), star.getDiameter() / 10, star.getDiameter() / 10);
            }
        }
    }


}
#include "AstronomerWindow.h"
#include <QMessageBox>

AstronomerWindow::AstronomerWindow(std::string _name, std::string _constellation, AstronomerModel* _model, QWidget *parent)
	: name{ _name }, constellation{ _constellation }, model{ _model }, QWidget(parent)
{
	ui.setupUi(this);
	this->ui.tableViewStars->setModel(this->model);

	this->ui.tableViewStars->resizeColumnsToContents();
	this->ui.tableViewStars->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->ui.tableViewStars->setSelectionMode(QAbstractItemView::SingleSelection);

	this->ui.checkBoxFilterStars->setChecked(false);

	connect(this->ui.checkBoxFilterStars, &QCheckBox::clicked, this, &AstronomerWindow::filterStars);
	connect(this->ui.pushButtonAdd, &QPushButton::clicked, this, &AstronomerWindow::addStar);
	connect(this->ui.pushButtonUpdate, &QPushButton::clicked, this, &AstronomerWindow::updateStar);
	connect(this->model, &QAbstractTableModel::dataChanged, this, &AstronomerWindow::filterStars);
	connect(this->ui.pushButtonView, &QPushButton::clicked, this, &AstronomerWindow::drawConstellation);
}

AstronomerWindow::~AstronomerWindow()
{
}

void AstronomerWindow::filterStars() {
	if (this->ui.checkBoxFilterStars->isChecked()) {

		this->ui.checkBoxFilterStars->setChecked(false);
		this->ui.tableViewStars->setSelectionMode(QAbstractItemView::ExtendedSelection);
		this->ui.tableViewStars->selectAll();
		QModelIndexList selectedRows = this->ui.tableViewStars->selectionModel()->selectedRows();
		for (auto row : selectedRows) {
			this->ui.tableViewStars->setRowHidden(row.row(), false);
		}

		selectedRows = this->ui.tableViewStars->selectionModel()->selectedRows();
		for (auto row : selectedRows) {
			if (this->model->checkStar(row.row(), this->constellation) == false) {
				this->ui.tableViewStars->setRowHidden(row.row(), true);
			}
		}

		this->ui.tableViewStars->setSelectionMode(QAbstractItemView::SingleSelection);
		this->ui.tableViewStars->clearSelection();

		this->ui.checkBoxFilterStars->setChecked(true);
	}
	else {
		this->ui.tableViewStars->setSelectionMode(QAbstractItemView::ExtendedSelection);
		this->ui.tableViewStars->selectAll();

		QModelIndexList selectedRows = this->ui.tableViewStars->selectionModel()->selectedRows();
		for (auto row : selectedRows) {
			this->ui.tableViewStars->setRowHidden(row.row(), false);
		}

		this->ui.tableViewStars->setSelectionMode(QAbstractItemView::SingleSelection);
		this->ui.tableViewStars->clearSelection();
	}
}

void AstronomerWindow::addStar() {
	std::string name = this->ui.lineEditAddName->text().toStdString();
	std::string sRA = this->ui.lineEditAddRA->text().toStdString();
	std::string sDec = this->ui.lineEditAddDec->text().toStdString();
	std::string sDiameter = this->ui.lineEditAddDiameter->text().toStdString();

	try {
		this->model->addStar(name, this->constellation, sRA, sDec, sDiameter);
	}
	catch (std::exception& ex) {
		QMessageBox* error = new QMessageBox{};
		error->setText(ex.what());
		error->show();
	}

	this->ui.lineEditAddName->clear();
	this->ui.lineEditAddRA->clear();
	this->ui.lineEditAddDec->clear();
	this->ui.lineEditAddDiameter->clear();
}

void AstronomerWindow::updateStar() {
	std::string name = this->ui.lineEditUpdateName->text().toStdString();
	std::string sRA = this->ui.lineEditUpdateRA->text().toStdString();
	std::string sDec = this->ui.lineEditUpdateDec->text().toStdString();
	std::string sDiameter = this->ui.lineEditUpdateDiameter->text().toStdString();

	QModelIndexList correctSelectedRows = this->ui.tableViewStars->selectionModel()->selectedRows();
	if (correctSelectedRows.size() <= 0) {
		return;
	}

	std::string starName = correctSelectedRows[0].data().toString().toStdString();

	try {
		this->model->updateStar(starName, name, this->constellation, sRA, sDec, sDiameter);
	}
	catch (std::exception& ex) {
		QMessageBox* error = new QMessageBox{};
		error->setText(ex.what());
		error->show();
	}

	this->ui.lineEditUpdateName->clear();
	this->ui.lineEditUpdateRA->clear();
	this->ui.lineEditUpdateDec->clear();
	this->ui.lineEditUpdateDiameter->clear();
}


void AstronomerWindow::drawConstellation() {
	QModelIndexList selectedRows = this->ui.tableViewStars->selectionModel()->selectedRows();
	if (selectedRows.size() <= 0) {
		return;
	}

	std::string starName = this->model->getStar(selectedRows[0].row());
	std::string starConstellation = this->model->getConstellation(selectedRows[0].row());

	ConstellationWindow* w = new ConstellationWindow{ this->model->getServ(), starConstellation, starName};
	w->show();

}
#include "AstronomerModel.h"

AstronomerModel::AstronomerModel(Service& _serv, QObject* parent) : serv{ _serv } {};

int AstronomerModel::rowCount(const QModelIndex& parent) const {
	return this->serv.getStars().size();
}

int AstronomerModel::columnCount(const QModelIndex& parent) const {
	return 5;
}

QVariant AstronomerModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();

	if (row >= this->serv.getStars().size()) {
		return QVariant{};
	}

	std::vector<Star>stars = this->serv.getSortedStars();

	if (role == Qt::DisplayRole) {
		if (col == 0) {
			return QVariant{ QString::fromStdString(stars[row].getName()) };
		}
		else if (col == 1) {
			return QVariant{ QString::fromStdString(stars[row].getConstellation()) };
		}
		else if (col == 2) {
			return QVariant{ QString::fromStdString(std::to_string(stars[row].getRA())) };
		}
		else if (col == 3) {
			return QVariant{ QString::fromStdString(std::to_string(stars[row].getDec())) };
		}
		else if (col == 4) {
			return QVariant{ QString::fromStdString(std::to_string(stars[row].getDiameter())) };
		}
	}

	return QVariant{};
}

Qt::ItemFlags AstronomerModel::flags(const QModelIndex& index) const {
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void AstronomerModel::addStar(std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter) {

	int rows = this->serv.getStars().size();
	this->beginInsertRows(QModelIndex{}, rows, rows);
	
	try {
		this->serv.addStar(name, constellation, sRA, sDec, sDiameter);
	}
	catch (std::exception& ex) {
		throw ex;
	}

	this->endInsertRows();

	emit dataChanged(QModelIndex{}, QModelIndex{});
}

void AstronomerModel::updateStar(std::string starName, std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter) {
	try {
		this->serv.updateStar(starName, name, constellation, sRA, sDec, sDiameter);
	}
	catch (std::exception& ex) {
		throw ex;
	}
	emit dataChanged(QModelIndex{}, QModelIndex{});
}
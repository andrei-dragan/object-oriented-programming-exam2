#pragma once
#include <QAbstractTableModel>
#include "Service.h"

class AstronomerModel : public QAbstractTableModel {
public:
	AstronomerModel(Service& _serv, QObject* parent = nullptr);
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex& index) const;
	bool checkStar(int row, std::string constellation) { return this->serv.checkStar(row, constellation); }
	void addStar(std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter);
	void updateStar(std::string starName, std::string name, std::string constellation, std::string sRA, std::string sDec, std::string sDiameter);
	std::string getStar(int idx) { return this->serv.getStar(idx); }
	std::string getConstellation(int idx) { return this->serv.getConstellation(idx); }
	Service& getServ() { return this->serv; }
private:
	Service& serv;
};
#pragma once
#include <string>
#include <iostream>
class Misiune
{
	int idRacheta, idAsteroid, cantitateExtrasa, combustibilConsumat, costCombustibil;
	double profitBrut, profitNet;
	std::string resursa;
public:
	Misiune();
	Misiune(const int& idRacheta, const int& idAsteroid, const std::string& resursa, const int& cantitateExtrasa, const int& combustibilConsumat, const int& costCombustibil, const double& profitBrut, const double& profitNet);
	~Misiune();

	friend std::ostream& operator<<(std::ostream& out, const Misiune& misiune);
	Misiune& operator=(const Misiune& misiune);

	void resetareValori();

	int getIdRacheta() const;
	int getIdAsteroid() const;
	int getCantitateExtrasa() const;
	int getCombustibilConsumat() const;
	int getCostCombustibil() const;
	double getProfitBrut() const;
	double getProfitNet() const;
	std::string getResursa() const;
};


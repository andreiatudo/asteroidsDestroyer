#pragma once
#include <iostream>
#include <string>
class Piata
{
	std::string resursa;
	int cantitateVanduta;
	double pretMinim, pretMaxim, pretActual;
public:
	Piata();
	Piata(const std::string& resursa, const double& pretMinim, const double& pretMaxim, const int& cantitateVanduta, const double& pretActual);
	~Piata();

	friend std::ostream& operator<<(std::ostream& out, const Piata& piata);
	Piata& operator=(const Piata& piata);

	std::string getResursa() const;
	double getPretMinim() const;
	double getPretMaxim() const;
	double getPretActual() const;
	int getCantitateVanduta() const;

	void setPretMaxim();
	void setCantitateVanduta(const int& cantitateVanduta);
};


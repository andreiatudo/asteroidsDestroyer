#pragma once
#include <iostream>
class Racheta
{
	int capacitate, consumCombustibil, combustibilDisponibil;
	double pret;
	const int id;
	static int numarRacheta;
public:
	Racheta();
	Racheta(const int& capacitate, const int& consumCombustibil, const int& combustibilDisponibil, const double& pret);
	~Racheta();

	Racheta& operator=(const Racheta& racheta);
	friend std::ostream& operator<<(std::ostream& out, const Racheta& racheta);

	const int getId() const;
	static int getNumarRacheta();
	double getPret() const;
	int getConsumCombustibil() const;
	int getCapacitate() const;
	int getCombustibilDisponibil() const;
};


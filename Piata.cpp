#include "Piata.h"

Piata::Piata()
{
	resursa = "";
	pretMaxim = 0;
	pretMinim = 0;
	cantitateVanduta = 0;
	pretActual = 0;
}

Piata::Piata(const std::string& resursa, const double& pretMinim, const double& pretMaxim, const int& cantitateVanduta, const double& pretActual)
{
	this->resursa = resursa;
	this->pretMaxim = pretMaxim;
	this->pretMinim = pretMinim;
	this->cantitateVanduta = cantitateVanduta;
	this->pretActual = pretActual;
}

Piata::~Piata()
{
}

Piata& Piata::operator=(const Piata& piata)
{
	if (this == &piata)
	{
		return *this;
	}
	this->resursa = piata.resursa;
	this->pretMaxim = piata.pretMaxim;
	this->pretMinim = piata.pretMinim;
	this->cantitateVanduta = piata.cantitateVanduta;
	this->pretActual = piata.pretActual;
	// TODO: insert return statement here
	return *this;
}

std::string Piata::getResursa() const
{
	return resursa;
}

double Piata::getPretMinim() const
{
	return pretMinim;
}

double Piata::getPretMaxim() const
{
	return pretMaxim;
}

double Piata::getPretActual() const
{
	return pretActual;
}

int Piata::getCantitateVanduta() const
{
	return cantitateVanduta;
}

void Piata::setPretMaxim()
{
	if (pretMaxim * 0.9 >= pretMinim)
		pretMaxim = pretMaxim * 0.9;
	else
		pretMaxim = pretMinim;
}

void Piata::setCantitateVanduta(const int& cantitateVanduta)
{
	this->cantitateVanduta += cantitateVanduta;
}

std::ostream& operator<<(std::ostream& out, const Piata& piata)
{
	out << "Resursa de pe piata este: " << piata.resursa << '\n';
	out << "Pretul maxim al resursei de pe piata este: " << piata.pretMaxim << '\n';
	out << "Pretul minim al resursei de pe piata este: " << piata.pretMinim << '\n';
	out << "Cantitatea vanduta este: " << piata.cantitateVanduta << '\n';
	out << "Pretul actual este: " << piata.pretActual << '\n';
	// TODO: insert return statement here
	return out;
}

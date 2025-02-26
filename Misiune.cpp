#include "Misiune.h"

Misiune::Misiune()
{
	idAsteroid = 0;
	idRacheta = 0;
	cantitateExtrasa = 0;
	combustibilConsumat = 0;
	costCombustibil = 0;
	profitBrut = 0;
	profitNet = 0;
	resursa = "";
}

Misiune::Misiune(const int& idRacheta, const int& idAsteroid, const std::string& resursa, const int& cantitateExtrasa, const int& combustibilConsumat, const int& costCombustibil, const double& profitBrut, const double& profitNet)
{
	this->idAsteroid = idAsteroid;
	this->idRacheta = idRacheta;
	this->cantitateExtrasa = cantitateExtrasa;
	this->combustibilConsumat = combustibilConsumat;
	this->costCombustibil = costCombustibil;
	this->profitNet = profitNet;
	this->profitBrut = profitBrut;
	this->resursa = resursa;
}

Misiune::~Misiune()
{
}

Misiune& Misiune::operator=(const Misiune& misiune)
{
	if (this == &misiune)
	{
		return *this;
	}
	this->idAsteroid = misiune.idAsteroid;
	this->idRacheta = misiune.idRacheta;
	this->cantitateExtrasa = misiune.cantitateExtrasa;
	this->combustibilConsumat = misiune.combustibilConsumat;
	this->costCombustibil = misiune.costCombustibil;
	this->profitNet = misiune.profitNet;
	this->profitBrut = misiune.profitBrut;
	this->resursa = misiune.resursa;
	// TODO: insert return statement here
	return *this;
}

void Misiune::resetareValori()
{
	idAsteroid = 0;
	idRacheta = 0;
	cantitateExtrasa = 0;
	combustibilConsumat = 0;
	costCombustibil = 0;
	profitBrut = 0;
	profitNet = 0;
	resursa = "";
}

int Misiune::getIdRacheta() const
{
	return idRacheta;
}

int Misiune::getIdAsteroid() const
{
	return idAsteroid;
}

int Misiune::getCantitateExtrasa() const
{
	return cantitateExtrasa;
}

int Misiune::getCombustibilConsumat() const
{
	return combustibilConsumat;
}

int Misiune::getCostCombustibil() const
{
	return costCombustibil;
}

double Misiune::getProfitBrut() const
{
	return profitBrut;
}

double Misiune::getProfitNet() const
{
	return profitNet;
}

std::string Misiune::getResursa() const
{
	return resursa;
}

std::ostream& operator<<(std::ostream& out, const Misiune& misiune)
{
	out << "Id-ul asteroidului din misiune este: " << misiune.idAsteroid << '\n';
	out << "Id-ul rachetei din misiune este: " << misiune.idRacheta << '\n';
	out << "Cantitatea extrasa din misiune este: " << misiune.cantitateExtrasa << '\n';
	out << "Combustibilul consumat din misiune este: " << misiune.combustibilConsumat << '\n';
	out << "Costul combustibilului din misiune este: " << misiune.costCombustibil << '\n';
	out << "Profitul net din misiune este: " << misiune.profitNet << '\n';
	out << "Profitul brut din misiune este: " << misiune.profitBrut << '\n';
	out << "Resursa extrasa din misiune este: " << misiune.resursa << '\n';
	// TODO: insert return statement here
	return out;
}

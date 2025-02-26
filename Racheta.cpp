#include "Racheta.h"

int Racheta::numarRacheta = 0;

Racheta::Racheta() : id(++numarRacheta)
{
	capacitate = 0;
	consumCombustibil = 0;
	combustibilDisponibil = 0;
	pret = 0.0f;
}

Racheta::Racheta(const int& capacitate, const int& consumCombustibil, const int& combustibilDisponibil, const double& pret) : id(++numarRacheta)
{
	this->capacitate = capacitate;
	this->consumCombustibil = consumCombustibil;
	this->combustibilDisponibil = combustibilDisponibil;
	this->pret = pret;
}

Racheta::~Racheta()
{
}

Racheta& Racheta::operator=(const Racheta& racheta)
{
	if (this == &racheta)
	{
		return *this;
	}
	this->capacitate = racheta.capacitate;
	this->consumCombustibil = racheta.consumCombustibil;
	this->combustibilDisponibil = racheta.combustibilDisponibil;
	this->pret = racheta.pret;
	// TODO: insert return statement here
	return *this;
}

const int Racheta::getId() const
{
	return id;
}

int Racheta::getNumarRacheta()
{
	return numarRacheta;
}

double Racheta::getPret() const
{
	return pret;
}

int Racheta::getConsumCombustibil() const
{
	return consumCombustibil;
}

int Racheta::getCapacitate() const
{
	return capacitate;
}

int Racheta::getCombustibilDisponibil() const
{
	return combustibilDisponibil;
}

std::ostream& operator<<(std::ostream& out, const Racheta& racheta)
{
	out << "Capacitatea rachetei este: " << racheta.capacitate << '\n';
	out << "Consumul combustibului rachetei este: " << racheta.consumCombustibil << '\n';
	out << "Combustibilul disponibil pt racheta este: " << racheta.combustibilDisponibil << '\n';
	out << "Pretul combustibilului pt racheta este: " << racheta.pret << '\n';
	out << "Id-ul rachetei este " << racheta.getId() << '\n';
	return out;
}

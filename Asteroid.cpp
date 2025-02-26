#include "Asteroid.h"

//int Asteroid::nrAsteroid = 0;

Asteroid::Asteroid()/* : id(++nrAsteroid)*/
{
	id = 0;
	resursa = "";
	cantitateTotala = 0;
	randamentExtractie = 0;
	distanta = 0;
}

Asteroid::Asteroid(const int& id, const std::string& resursa, const int& cantitateTotala, const int& randamentExtractie, const int& distanta) /*: id(++nrAsteroid)*/
{
	this->id = id;
	this->resursa = resursa;
	this->cantitateTotala = cantitateTotala;
	this->randamentExtractie = randamentExtractie;
	this->distanta = distanta;
}

Asteroid::~Asteroid()
{
}

Asteroid& Asteroid::operator=(const Asteroid& asteroid)
{
	if (this == &asteroid)
	{
		return *this;
	}
	this->id = asteroid.id;
	this->resursa = asteroid.resursa;
	this->cantitateTotala = asteroid.cantitateTotala;
	this->randamentExtractie = asteroid.randamentExtractie;
	this->distanta = asteroid.distanta;
	// TODO: insert return statement here
	return *this;
}

int Asteroid::getId() const
{
	return id;
}

int Asteroid::getCantitateTotala() const
{
	return cantitateTotala;
}

int Asteroid::getRandamentExtractie() const
{
	return randamentExtractie;
}

int Asteroid::getDistanta() const
{
	return distanta;
}

std::string Asteroid::getResursa() const
{
	return resursa;
}

void Asteroid::setCantitateTotala(const int& cantitate)
{
	this->cantitateTotala = ((cantitate * 100) + this->randamentExtractie - 1) / this->randamentExtractie;
}

//int Asteroid::getNrAsteroid()
//{
//	return nrAsteroid;
//}
//
//const int Asteroid::getId() const
//{
//	return id;
//}

std::ostream& operator<<(std::ostream& out, const Asteroid& asteroid)
{
	out << "Id-ul asteroidului este: " << asteroid.id << '\n';
	out << "Resursa de pe asteroid este: " << asteroid.resursa << '\n';
	out << "Cantitatea totala este: " << asteroid.cantitateTotala << '\n';
	out << "Randamentul extractiei este: " << asteroid.randamentExtractie << '\n';
	out << "Distanta pana la asteroid este: " << asteroid.distanta << '\n';
	// TODO: insert return statement here
	return out;
}

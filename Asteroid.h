#pragma once
#include <string>
#include <iostream>

class Asteroid
{
	/*const int id;
	static int nrAsteroid;*/
	int id;
	std::string resursa;
	int cantitateTotala, randamentExtractie, distanta;
public:
	Asteroid();
	Asteroid(const int& id, const std::string& resursa, const int& cantitateTotala, const int& randamentExtractie, const int& distanta);
	~Asteroid();

	Asteroid& operator=(const Asteroid& asteroid);
	friend std::ostream& operator<<(std::ostream& out, const Asteroid& asteroid);

	/*static int getNrAsteroid();
	const int getId() const;*/
	int getId() const;
	int getCantitateTotala() const;
	int getRandamentExtractie() const;
	int getDistanta() const;
	std::string getResursa() const;
	void setCantitateTotala(const int& cantitate);
};


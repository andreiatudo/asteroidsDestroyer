#pragma once
#include "Asteroid.h"
#include "Piata.h"
#include "Racheta.h"
#include <fstream>
#include <vector>
#include "Misiune.h"
#include <algorithm>
#include <tuple>
#include <iomanip>

std::vector<Asteroid> citireAsteroizi(const char* denumireFisier);
std::vector<Racheta> citireRachete(const char* denumireFisier);
std::vector<Piata> citirePiata(const char* denumireFisier);

std::vector<int> calculareKgTotalePerAsteroid(const std::vector<Asteroid>& asteroizi);
std::vector<int> distantePerAsteroid(const std::vector<Asteroid>& asteroizi);
std::vector<Misiune> creareMisiuni(const std::vector<Racheta>& rachete, std::vector<Asteroid>& asteroizi, std::vector<Piata>& piete);
void creareFisiere(const std::vector<Misiune>& misiuni, const size_t& nrRachete, std::vector<Piata>& piete);
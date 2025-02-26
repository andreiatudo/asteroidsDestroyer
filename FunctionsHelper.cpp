#include "FunctionsHelper.h"

std::vector<Asteroid> citireAsteroizi(const char* denumireFisier) {
	std::ifstream f(denumireFisier);
	std::string linie;
	size_t poz;
	std::vector<Asteroid> asteroizi;

	if (!f.is_open()) {
		std::cerr << "Eroare la deschiderea fisierului: " << denumireFisier << std::endl;
		return asteroizi;
	}

	std::getline(f, linie);

	while (std::getline(f, linie)) {
		size_t poz = 0;
		int nr = 0;
		int cantitateTotala = 0, randamentExtractie = 0, distanta = 0, id = 0;
		std::string resursa;
		std::string idStr;

		while ((poz = linie.find(';')) != std::string::npos) {
			std::string sub = linie.substr(0, poz);

			if (nr == 0) {
				idStr = sub.substr(1);
				id = std::stoi(idStr);
			}
			else if (nr == 1) {
				resursa = sub;
			}
			else if (nr == 2) {
				cantitateTotala = std::stoi(sub);
			}
			else if (nr == 3) {
				randamentExtractie = std::stoi(sub);
			}
			else if (nr == 4) {
				distanta = std::stoi(sub);
			}

			linie.erase(0, poz + 1);
			nr++;
		}

		if (!linie.empty()) {
			distanta = std::stoi(linie);
		}

		Asteroid asteroid(id, resursa, cantitateTotala, randamentExtractie, distanta);
		asteroizi.push_back(asteroid);
	}

	return asteroizi;
}


std::vector<Racheta> citireRachete(const char* denumireFisier) {
	std::ifstream f(denumireFisier);
	std::string linie;
	size_t poz;
	std::vector<Racheta> rachete;

	if (!f.is_open()) {
		std::cerr << "Eroare la deschiderea fisierului: " << denumireFisier << std::endl;
		return rachete;
	}

	std::getline(f, linie);

	while (std::getline(f, linie)) {
		size_t poz = 0;
		int nr = 0;
		int capacitate = 0, consumCombustibil = 0, combustibilDisponibil = 0;
		double pret = 0.0;
		std::string idStr;

		while ((poz = linie.find(';')) != std::string::npos) {
			std::string sub = linie.substr(0, poz);

			if (nr == 0) {
				idStr = sub.substr(1);
				int id = std::stoi(idStr);
			}
			else if (nr == 1) {
				capacitate = std::stoi(sub);
			}
			else if (nr == 2) {
				consumCombustibil = std::stoi(sub);
			}
			else if (nr == 3) {
				combustibilDisponibil = std::stoi(sub);
			}
			else if (nr == 4) {
				pret = std::stof(sub);
			}

			linie.erase(0, poz + 1);
			nr++;
		}

		if (!linie.empty()) {
			pret = std::stof(linie);
		}

		Racheta racheta(capacitate, consumCombustibil, combustibilDisponibil, pret);
		rachete.push_back(racheta);
	}
	return rachete;
}


std::vector<Piata> citirePiata(const char* denumireFisier)
{
	std::ifstream f(denumireFisier);
	std::string linie;
	std::vector<Piata> piete;
	std::getline(f, linie);
	while (std::getline(f, linie)) {
		size_t poz = 0;
		int nr = 0;
		std::string resursa;
		double pretMinim = 0, pretMaxim = 0;

		while ((poz = linie.find(';')) != std::string::npos) {
			std::string sub = linie.substr(0, poz);

			if (nr == 0) {
				resursa = sub;
			}
			else if (nr == 1) {
				pretMinim = std::stod(sub);
			}
			else if (nr == 2) {
				pretMaxim = std::stod(sub);
			}

			linie.erase(0, poz + 1);
			nr++;
		}

		if (!linie.empty()) {
			pretMaxim = std::stoi(linie);
		}

		Piata piata(resursa, pretMinim, pretMaxim, 0, pretMaxim);
		piete.push_back(piata);
	}
	return piete;
}
std::vector<int> calculareKgTotalePerAsteroid(const std::vector<Asteroid>& asteroizi)
{
	int maxim = -1;
	for (const Asteroid& asteroid : asteroizi)
	{
		if (asteroid.getId() > maxim)
		{
			maxim = asteroid.getId();
		}
	}
	std::vector<int> kgTotalePerAsteroid(maxim + 1, 0);
	for (const Asteroid& asteroid : asteroizi)
	{
		kgTotalePerAsteroid[asteroid.getId()] += asteroid.getCantitateTotala() * asteroid.getRandamentExtractie() / 100;
	}
	return kgTotalePerAsteroid;
}

std::vector<int> distantePerAsteroid(const std::vector<Asteroid>& asteroizi)
{
	int maxim = -1;
	for (const Asteroid& asteroid : asteroizi)
	{
		if (asteroid.getId() > maxim)
		{
			maxim = asteroid.getId();
		}
	}
	std::vector<int> distantelePerAsteroid(maxim + 1, 0);
	for (const Asteroid& asteroid : asteroizi)
	{
		distantelePerAsteroid[asteroid.getId()] = asteroid.getDistanta();
	}
	return distantelePerAsteroid;
}

std::vector<Misiune> creareMisiuni(const std::vector<Racheta>& rachete, std::vector<Asteroid>& asteroizi, std::vector<Piata>& piete)
{
	std::vector<Misiune> misiuni;
	std::vector<int> kgTotalePerAsteroid = calculareKgTotalePerAsteroid(asteroizi);
	std::vector<int> ordineRachete;
	std::vector<int> distantelePerAsteroid = distantePerAsteroid(asteroizi);
	int idRacheta = 0;
	for (int i = 1;i < kgTotalePerAsteroid.size();i++)
	{
		while (kgTotalePerAsteroid[i] > 0)
		{
			int distanta = 2 * distantelePerAsteroid[i] / 1000;
			double minim = 100000000;
			for (const Racheta& racheta : rachete)
			{
				double cost = distanta * racheta.getConsumCombustibil() * racheta.getPret();
				if (distanta * racheta.getConsumCombustibil() < racheta.getCombustibilDisponibil())
				{
					if (kgTotalePerAsteroid[i] % racheta.getCapacitate() != 0)
					{
						cost = cost * ((kgTotalePerAsteroid[i] / racheta.getCapacitate()) + 1);
					}
					else
					{
						cost = cost * (kgTotalePerAsteroid[i] / racheta.getCapacitate());
					}
					if (cost < minim)
					{
						minim = cost;
						idRacheta = racheta.getId();
					}
				}
			}
			idRacheta--;
			ordineRachete.push_back(idRacheta);
			if (idRacheta >= 0 && idRacheta <= rachete.size()) {
				kgTotalePerAsteroid[i] -= rachete[idRacheta].getCapacitate();
			}
			else {
				std::cout << "Eroare: idRacheta invalid!\n";
				std::cout << idRacheta << '\n';
			}

		}
	}
	int nr = 0, indiceleResursei = 0;
	for (int i = 0;i < ordineRachete.size();i++)
	{
		int idRacheta = ordineRachete[i] + 1, idAsteroid = asteroizi[nr].getId();
		std::string resursa;
		int cantitateExtrasa = 0, combustibilConsumat = 0, costCombustibil = 0;
		double profitBrut = 0.0f, profitNet = 0.0f;
		if (2 * asteroizi[nr].getDistanta() % 1000 != 0)
		{
			combustibilConsumat = ((2 * asteroizi[nr].getDistanta() / 1000) + 1) * rachete[ordineRachete[i]].getConsumCombustibil();
		}
		else
		{
			combustibilConsumat = (2 * asteroizi[nr].getDistanta() / 1000) * rachete[ordineRachete[i]].getConsumCombustibil();
		}
		costCombustibil = (int)(combustibilConsumat * rachete[ordineRachete[i]].getPret());
		if (asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100 <= rachete[ordineRachete[i]].getCapacitate())
		{
			cantitateExtrasa += asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100;
			resursa = asteroizi[nr].getResursa();
			for (int k = 0;k < piete.size();k++)
			{
				if (piete[k].getResursa() == resursa)
				{
					int raport = piete[k].getCantitateVanduta() / 10000;
					piete[k].setCantitateVanduta(asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100);
					if (piete[k].getCantitateVanduta() / 10000 != raport)
					{
						piete[k].setPretMaxim();
					}
					profitBrut += (asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100) * piete[k].getPretMaxim();
					break;
				}
			}

			if (nr + 1 < asteroizi.size())
			{
				nr++;
				while (asteroizi[nr].getId() == asteroizi[nr - 1].getId())
				{
					if (rachete[ordineRachete[i]].getCapacitate() - cantitateExtrasa > asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100)
					{
						for (int k = 0;k < piete.size();k++)
						{
							if (piete[k].getResursa() == asteroizi[nr].getResursa())
							{
								int raport = piete[k].getCantitateVanduta() / 10000;
								piete[k].setCantitateVanduta(asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100);
								if (piete[k].getCantitateVanduta() / 10000 != raport)
								{
									piete[k].setPretMaxim();
								}
								profitBrut += (asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100) * piete[k].getPretMaxim();
								break;
							}
						}
						cantitateExtrasa += asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100;
						resursa += '&';
						resursa += asteroizi[nr].getResursa();
					}
					else
					{
						for (int k = 0;k < piete.size();k++)
						{
							if (piete[k].getResursa() == asteroizi[nr].getResursa())
							{
								int raport = piete[k].getCantitateVanduta() / 10000;
								piete[k].setCantitateVanduta(rachete[ordineRachete[i]].getCapacitate() - cantitateExtrasa);
								if (piete[k].getCantitateVanduta() / 10000 != raport)
								{
									piete[k].setPretMaxim();
								}
								profitBrut += (((asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie()) / 100) + cantitateExtrasa - rachete[ordineRachete[i]].getCapacitate()) * piete[k].getPretMaxim();
								break;
							}
						}
						asteroizi[nr].setCantitateTotala(((asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie()) / 100) + cantitateExtrasa - rachete[ordineRachete[i]].getCapacitate());
						cantitateExtrasa = rachete[ordineRachete[i]].getCapacitate();
						resursa += '&';
						resursa += asteroizi[nr].getResursa();
						break;
					}
					if (nr + 1 < asteroizi.size())
					{
						nr++;
					}
					else break;
				}
			}
		}
		else
		{
			resursa = asteroizi[nr].getResursa();
			cantitateExtrasa = rachete[ordineRachete[i]].getCapacitate();
			for (int k = 0;k < piete.size();k++)
			{
				if (piete[k].getResursa() == asteroizi[nr].getResursa())
				{
					int raport = piete[k].getCantitateVanduta() / 10000;
					piete[k].setCantitateVanduta(rachete[ordineRachete[i]].getCapacitate());
					if (piete[k].getCantitateVanduta() / 10000 != raport)
					{
						piete[k].setPretMaxim();
					}
					profitBrut += (rachete[ordineRachete[i]].getCapacitate()) * piete[k].getPretMaxim();
					break;
				}
			}
			asteroizi[nr].setCantitateTotala((asteroizi[nr].getCantitateTotala() * asteroizi[nr].getRandamentExtractie() / 100) - rachete[ordineRachete[i]].getCapacitate());
		}
		profitNet = profitBrut - costCombustibil;
		Misiune misiune(idRacheta, idAsteroid, resursa, cantitateExtrasa, combustibilConsumat, costCombustibil, profitBrut, profitNet);
		misiuni.push_back(misiune);
	}
	kgTotalePerAsteroid.clear();
	distantelePerAsteroid.clear();
	return misiuni;
}

void creareFisiere(const std::vector<Misiune>& misiuni, const size_t& nrRachete, std::vector<Piata>& piete)
{
	std::ofstream g1("misiuni.csv");

	std::ofstream g2("profit_total.csv");

	std::ofstream g3("profit_resursa.csv");

	std::ofstream g4("clasament_rachete.csv");

	g1 << "ID Rachetă;ID Asteroid;Resursă;Cantitate extrasă (kg);Combustibil consumat (kg);Cost combustibil ($);Profit brut ($);Profit net ($)" << std::endl;

	for (size_t i = 0;i < misiuni.size();i++)
	{
		g1 << 'R' << misiuni[i].getIdRacheta() << ';' << 'A' << misiuni[i].getIdAsteroid() << ';' << misiuni[i].getResursa() << ';' << misiuni[i].getCantitateExtrasa() << ';' << misiuni[i].getCombustibilConsumat() << ';' << misiuni[i].getCostCombustibil() << ';' << misiuni[i].getProfitBrut() << ';' << misiuni[i].getProfitNet();
		if (i != misiuni.size() - 1)
		{
			g1 << '\n';
		}
	}

	std::vector<std::tuple<int, int, int>> profitPerRacheta;
	g2 << "ID Rachetă;Profit brut ($);Cost total combustibil ($);Profit net ($)" << std::endl;

	for (size_t i = 0;i < nrRachete;i++)
	{
		int costTotalCombustibil = 0, nr = 0;
		double profitBrut = 0.0f;
		for (size_t j = 0;j < misiuni.size();j++)
		{
			if (misiuni[j].getIdRacheta() == i + 1)
			{
				nr++;
				profitBrut += misiuni[j].getProfitBrut();
				costTotalCombustibil += misiuni[j].getCostCombustibil();
			}
		}
		profitPerRacheta.push_back(std::make_tuple((i + 1), nr, profitBrut - costTotalCombustibil));
		g2 << 'R' << i + 1 << ';' << profitBrut << ';' << costTotalCombustibil << ';' << profitBrut - costTotalCombustibil;
		if (i != nrRachete - 1)
		{
			g2 << '\n';
		}
	}
	g3 << "Resursă;Cantitate extrasă (kg);Profit brut ($)" << std::endl;

	for (size_t i = 0;i < piete.size();i++)
	{
		g3 << piete[i].getResursa() << ';' << piete[i].getCantitateVanduta() << ';';
		
		double profitBrut = 0, pretActual = piete[i].getPretActual();
		while (piete[i].getCantitateVanduta() > 0)
		{
			int suma;
			if (piete[i].getCantitateVanduta() > 10000)
			{
				suma = 10000;
			}
			else
			{
				suma = piete[i].getCantitateVanduta();
			}
			profitBrut += suma * pretActual;
			piete[i].setCantitateVanduta(-10000);
			pretActual *= 0.9;
			if (piete[i].getPretMinim() > pretActual)
			{
				pretActual = piete[i].getPretMinim();
			}
		}
		g3 << profitBrut;
		if (i != piete.size() - 1)
		{
			g3 << '\n';
		}
	}


	std::sort(profitPerRacheta.begin(), profitPerRacheta.end(), [](const std::tuple<int, int, int>& a,
		const std::tuple<int, int, int>& b) {
			int profitA = std::get<2>(a);
			int nrMisiuniA = std::get<1>(a);
			int profitB = std::get<2>(b);
			int nrMisiuniB = std::get<1>(b);

			if (nrMisiuniA != 0 && nrMisiuniB != 0) {
				return profitA / nrMisiuniA > profitB / nrMisiuniB;
			}
			else if (nrMisiuniA != 0) {
				return true;
			}
			else if (nrMisiuniB != 0) {
				return false;
			}
			else {
				return false;
			}
		});

	g4 << "Loc;ID Rachetă;Profit net ($);Număr misiuni;Scor eficiență" << std::endl;

	int cnt = 0;
	for (const std::tuple<int, int, int>& t : profitPerRacheta)
	{
		cnt++;
		if (std::get<1>(t) != 0)
			g4 << cnt << ";R" << std::get<0>(t) << ';' << std::get<2>(t) << ';' << std::get<1>(t) << ';' << std::get<2>(t) / std::get<1>(t);
		else
			g4 << cnt << ";R" << std::get<0>(t) << ';' << std::get<2>(t) << ';' << std::get<1>(t) << ';' << '0';
		if (cnt != nrRachete)
		{
			g4 << '\n';
		}
	}
	profitPerRacheta.clear();
}

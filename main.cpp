#include "FunctionsHelper.h"
int main(int argc, char* argv[])
{
	std::vector<Asteroid> asteroizi = citireAsteroizi(argv[2]);
	std::vector<Racheta> rachete = citireRachete(argv[1]);
	std::vector<Piata> piete = citirePiata(argv[3]);
	std::vector<Misiune> misiuni=creareMisiuni(rachete, asteroizi, piete);
	creareFisiere(misiuni, rachete.size(), piete);
	asteroizi.clear();
	rachete.clear();
	piete.clear();
	misiuni.clear();
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
typedef vector <vector <int> > Carte;

struct Position
{
	int i, j;
};

bool binaire(Carte const& carte)
{
	for (auto ligne : carte)
	{
		for (auto element : ligne)
		{
			if (element != 0 and element != 1) return false;
		}
	}
	return true;
}

void affiche(Carte const& carte)
{
	for (auto ligne : carte)
	{
		for (auto element : ligne)
		{
			cout << element;
		}
		cout << endl;
	}
	cout << "----" << endl;
}

bool verifie_et_modifie(Carte& carte)
{

	if (binaire(carte) == false)
	{
		cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
		return false;
	}

	for (size_t i(1); i < carte.size(); ++i) {
		for (size_t j(1); j < carte[0].size(); ++j) {
			vector<vector<bool> > etang(carte.size(), vector<bool>(carte[0].size()));
			for (size_t b1(0); b1 < etang.size(); ++b1) {
				for (size_t b2(0); b2 < etang[b1].size(); ++b2) {
					etang[b1][b2] = false;
				}
			}
			bool bord(false);
			if (carte[i][j] != 1 && carte[i - 1][j] == 1 && carte[i][j - 1] == 1) {
				size_t x(i);
				size_t y(j);
				do {
					do {
						etang[x][y] = true;
						++y;
					} while (y < carte[0].size() && carte[x][y] != 1);
					if (y == carte[0].size()) {
						bord = true;
					}
					y = j;
					++x;
					if (x == carte.size()) {
						bord = true;
					}
				} while (x < carte.size() && carte[x][y] != 1 && !bord);
			}
			if (!bord) {
				for (size_t k(0); k < etang.size(); ++k) {
					for (size_t l(0); l < etang[k].size(); ++l) {
						if (etang[k][l]) {
							carte[k][l] = 1;
						}
					}
				}
			}
		}
	}
	return true;
	////Efacer les etangs
	//for (size_t i(1); i < carte.size()-1; ++i)
	//{
	//	for (size_t j(1); j < carte[0].size()-1; ++j)
	//	{
	//		if ((carte[i][j] == 0 and carte[i-1][j]==1 and carte[i][j+1]==0 and carte[i][j-1]==0 and carte[i-1][j]==0))
	//		{
	//			carte[i][j] = 1;
	//		}
	//	}
	//}
	//return true;

}

double longueur_cloture(Carte const& carte, double echelle = 2.5)
{
	double perimetre(0);
	int z(0), x(0), y(0);
	vector<int> gauche(carte.size());
	vector<int> droite(carte.size());
	vector<int> terre(carte.size());
	for (size_t i(0); i < carte.size(); ++i)
	{
		size_t j(0);
		int z(0);
		while (j < carte[i].size() && carte[i][j] != 1) ++j;
		gauche[i] = j;
		z = carte[i].size() - 1;
		while (z >= 0 && carte[i][z] != 1) --z;
		droite[i] = z + 1;
		terre[i] = z + 1 - j;
		if (terre[i] > 0) {
			perimetre += (2 * echelle);
			if (i > 0)
			{
				x = (gauche[i] - gauche[i - 1]);
				y = (droite[i] - droite[i - 1]);
				if (x < 0) x *= -1;
				if (y < 0) y *= -1;
				perimetre += x * echelle + y * echelle;
			}
		}
	}
	perimetre += terre[0] * echelle + terre[terre.size() - 1] * echelle;
	return perimetre;
}

void ajoute_unique(vector<int>& ensemble, int valeur)
{
	bool x(false);
	int i(0);
	while (i < ensemble.size() && x == false)
	{
		if (ensemble[i] == valeur) {
			x = true;
		}
		++i;
	}
	if (x == false) {
		ensemble.push_back(valeur);
	}
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
	return true;
}
bool convexite_lignes(Carte& carte)
{
	return true;
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	Carte carte = {
	  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
	  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	  {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
	  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	  {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	cout << "Carte au départ :" << endl;
	affiche(carte);
	if (verifie_et_modifie(carte)) {
		cout << "Carte après modification :" << endl;
		affiche(carte);
		cout << "Il vous faut " << longueur_cloture(carte)
			<< " mètres de clôture pour votre terrain."
			<< endl;
	}

	return 0;
}
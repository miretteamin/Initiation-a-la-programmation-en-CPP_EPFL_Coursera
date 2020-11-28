#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int> ligne)
{
	int max(0), somme(0);

	for (size_t i = 0; i < ligne.size(); ++i)
	{
		if (ligne[i] != 0)
		{
			somme += ligne[i];
			if (somme > max) max = somme;
		}
		else somme = 0;
	}

	return max;
}

vector<size_t> lignes_max(vector<vector<int>> tableau)
{
	vector<size_t> resultat;
	vector<size_t> temp;
	int max(0), somme(0);

	for (auto ligne : tableau)
	{
		somme = somme_consecutifs_max(ligne);
		if (somme > max) max = somme;
		temp.push_back(somme);
	}

	for (size_t i = 0; i < temp.size(); i++)
	{
		if (temp[i] == max) resultat.push_back(i);
	}

	return resultat;
}

vector<vector<int>> tranches_max(vector<vector<int>> tableau)
{
	vector<vector<int>> resultat;

	vector<size_t> lignes = lignes_max(tableau);

	for (size_t i = 0; i < lignes.size(); i++) resultat.push_back(tableau[lignes[i]]);

	return resultat;
}

int main()
{

	vector<vector<int>> tableau = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{5, 0, 5},
		{1, 1, 1, 1, 1, 1, 1}
	};

	vector<vector<int>> resultat = tranches_max(tableau);

	return 0;
}
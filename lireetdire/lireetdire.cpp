#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
	int dix(1);
	int temp(nombre);
	while (temp >= 10) {
		dix *= 10;
		temp /= 10;
	}
	nombre %= dix;
	return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre = (nombre * 10) + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int& nombre)
{
	int cnt(1), temp(0), digit(0), digit2(0), dix(10),tempnb(0);

	do
	{
		digit = separer_chiffre_gauche(nombre);
		while (true)
		{
			digit2 = separer_chiffre_gauche(nombre);

			if (digit2 == digit) cnt++;
			else
			{
				tempnb = nombre;
				while (tempnb > 0)
				{
					dix *= 10;
					tempnb /= 10;
				}

				nombre = nombre + (dix * digit2);
				break;
			}
		}

		dire_chiffre(temp, cnt, digit);
		cnt = 1;
		dix = 10;

	} while (nombre != 0);

	return temp;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
	while (fois-- > 0) {
		nombre = lire_et_dire(nombre);
	}
}

int main()
{
	int nombre(1);
	int fois(1);
	cin >> nombre >> fois;
	repeter_lire_et_dire(nombre, fois);
	cout << nombre << endl;
	return 0;
}

#include <iostream>
using namespace std;

int demander_annee()
{
	int annee(0);
	do
	{
		cout << " Entrez une annee (1583 - 4000) : ";
		cin >> annee;
	} while (annee < 1583 or annee > 4000);

	return annee;
}

void affiche_date(int annee, int nbjour)
{
	string mois;

	if (nbjour <= 31)
	{
		mois = " mars";
	}
	else if (nbjour >= 32)
	{
		nbjour -= 31;
		mois = " avril";
	}
	cout << " Date de Paques en " << annee << " : " << nbjour << mois << endl;
}

int date_Paques(int annee)
{
	//Gauss algorithm

	const int siecle(annee / 100);
	const int p((13 + 8 * siecle) / 25);
	const int q(siecle / 4);
	const int M((15 - p + siecle - q) % 30);
	const int N((4 + siecle - q) % 7);
	const int d((M + 19 * (annee % 19)) % 30);
	const int e((2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7);

	int jour(e + d + 22);
	if (e == 6 and (d == 29 or (d == 28 and ((11 * (M + 1)) % 30) < 19)))
	{
		jour -= 7;
	}

	return jour;
}

int main()
{
	int annee, nbjour;
	annee = demander_annee();
	nbjour = date_Paques(annee);
	affiche_date(annee, nbjour);
	return 0;
}
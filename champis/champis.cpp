#include <iostream>
using namespace std;

int main()
{
	bool l, a, c, f;
	cout << "Pensez � un champignon : amanite tue-mouches, pied bleu, girolle," << endl
		<< "c�pe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin >> c;
	cout << endl;
	if (c == 0)
	{
		cout << "Est - ce que votre champignon a des lamelles(1 : oui, 0 : non) ?";
		cin >> l;
		cout << endl;
		if (l == 0)
		{
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "le c�pe de Bordeaux";
		}
		else
		{
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> a;
			cout << endl;
			if (a == 1)
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "le coprin chevelu";
			}
			else
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "la girolle";
			}
		}
	}
	else
	{
		cout << "Est-ce que votre champignon vit en for�t (1 : oui, 0 : non) ? ";
		cin >> f;
		cout << endl;
		if (f == 1)
		{
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> a;
			cout << endl;
			if (a == 1)
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "l'amanite tue-mouches";
			}
			else
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "le pied bleu";
			}
		}
		else
		{
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "l'agaric jaunissant";
		}
	}

	return 0;
}
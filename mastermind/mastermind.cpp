#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
													* all compilers seems to support it :-( */

char tirer_couleur()
{
	static const char* const couleurs = ".RGBCYM";
	static const int nb = strlen(couleurs) - 1;

	return couleurs[distribution(generateur,
		std::uniform_int_distribution<int>::param_type{ 0, nb })];
}

// ======================================================================
char poser_question()
{
	char lu(' ');
	cout << "Entrez une couleur : ";
	cin >> lu;
	return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
	char lu(poser_question());
	while (not couleur_valide(lu)) {
		cout << "'" << lu << "' n'est pas une couleur valide." << endl;
		cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
		lu = poser_question();
	}
	return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
	cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
	while (nb-- > 0) {
		cout << c;
	}
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4)
{
	afficher_couleurs(c1, c2, c3, c4);
	cout << " : ";
	afficher_reponses(c1, c2, c3, c4,
		r1, r2, r3, r4);
	cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
	cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
	cout << "Perdu :-(" << endl;
	cout << "La bonne combinaison était : ";
	afficher_couleurs(c1, c2, c3, c4);
	cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

 // ======================================================================
bool couleur_valide(char c)
{
	if (c == '.' or c == 'R' or c == 'G' or c == 'B' or c == 'C' or c == 'Y' or c == 'M')
	{
		return true;
	}
	else return false;
}

// ======================================================================
bool verifier(char c1, char& c2, int& score
)
{
	if (c1 == c2)
	{
		++score;
		c2 = 'x';
		return true;
	}
	else return false;
}

// ======================================================================
void apparier(char couleurpropose, char& c1, char& c2, char& c3, int& score
)
{
	if (verifier(couleurpropose, c1, score) == false)
	{
		if (verifier(couleurpropose, c2, score) == false)
		{
			verifier(couleurpropose, c3, score);
		}
	}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4)
{
	int correcte(0), semicorrecte(0), faux(0);

	if (c1 == r1)
	{
		++correcte;
		r1 = 'x';
	}
	if (c2 == r2)
	{
		++correcte;
		r2 = 'x';
	}
	if (c3 == r3)
	{
		++correcte;
		r3 = 'x';
	}
	if (c4 == r4)
	{
		++correcte;
		r4 = 'x';
	}
	if (r1 != 'x')
	{
		apparier(c1, r2, r3, r4, semicorrecte);
	}
	if (r2 != 'x')
	{
		apparier(c2, r1, r3, r4, semicorrecte);
	}
	if (r3 != 'x')
	{
		apparier(c3, r1, r2, r4, semicorrecte);
	}
	if (r4 != 'x')
	{
		apparier(c4, r1, r2, r3, semicorrecte);
	}

	faux = 4 - correcte - semicorrecte;

	afficher(correcte, '#');
	afficher(semicorrecte, '+');
	afficher(faux, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4)
{
	if (c1 == r1 && c2 == r2 && c3 == r3 && c4 == r4) return true;
	else return false;
}

// ======================================================================
void jouer(int maxcoup = 8
)
{
	char ci1(tirer_couleur());
	char ci2(tirer_couleur());
	char ci3(tirer_couleur());
	char ci4(tirer_couleur());

	char c1('l');
	char c2('l');
	char c3('l');
	char c4('l');

	int nbcoup(0);

	do
	{
		c1 = lire_couleur();
		c2 = lire_couleur();
		c3 = lire_couleur();
		c4 = lire_couleur();

		afficher_coup(c1, c2, c3, c4, ci1, ci2, ci3, ci4);

		++nbcoup;

	} while (!gagne(c1, c2, c3, c4, ci1, ci2, ci3, ci4) && nbcoup < maxcoup);

	if (gagne(c1, c2, c3, c4, ci1, ci2, ci3, ci4))
	{
		message_gagne(nbcoup);
	}
	else
	{
		message_perdu(ci1, ci2, ci3, ci4);
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	jouer();
	return 0;
}

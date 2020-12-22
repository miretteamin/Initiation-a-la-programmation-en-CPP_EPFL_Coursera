#include <iostream>
using namespace std;

char decale(char c, char debut, int decalage)
{
	while (decalage < 0)
	{
		decalage += 26;
	}

	return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int d)
{
	if (c >= 'a' and c <= 'z') return decale(c, 'a', d);
	else if (c >= 'A' and c <= 'Z') return decale(c, 'A', d);
	else return c;

}

string code(string phrase, int d)
{
	for (size_t i = 0; i < phrase.size(); ++i)
	{
		phrase[i] = code((phrase[i]), d);
	}

	return phrase;
}

string decode(string phrase, int d)
{
	d *= -1;
	for (size_t i = 0; i < phrase.size(); ++i)
	{
		phrase[i] = code(phrase[i], d);
	}

	return phrase;
}

int main()
{
	cout << code("Fuyez manants", 4) << "lorsqu’elle reçoit la chaîne Fuyez manants et un décalage de 4" << endl;
	cout << "Sa decodage: " << decode("Jycid qererxw", 4) << endl << endl;
	cout << code("Fuyez manants", 6) << "lorsqu’elle reçoit la chaîne Fuyez manants et un décalage de 6" << endl;
	cout << "Sa decodage: " << decode("Laekf sgtgtzy", 6) << endl << endl;
	cout << code("Fuyez manants", -4) << "lorsqu’elle reçoit la chaîne Fuyez manants et un décalage de -4" << endl;
	cout << "Sa decodage: " << decode("Bquav iwjwjpo", -4) << endl << endl;
	cout << code("Avez-vous vu mes 3 chats et mes 2 chiens ?", -4) << "lorsqu’elle reçoit la chaîne Avez-vous vu mes 3 chats et mes 2 chiens ? et un décalage de 4" << endl;
	cout << "Sa decodage: " << decode("Avez-vous vu mes 3 chats et mes 2 chiens ?", 4) << endl;

	return 0;
}
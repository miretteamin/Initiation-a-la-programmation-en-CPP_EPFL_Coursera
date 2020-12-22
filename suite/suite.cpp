#include <iostream>
using namespace std;

int main()
{
    int debut(0);
    do {
        cout << "de (>= 1) ? ";
        cin >> debut;
    } while (debut < 1);

    int fin(0);
    do {
        cout << "a (>= " << debut << ") ? ";
        cin >> fin;
    } while (fin < debut);

    /*******************************************
     * Completez le programme a partir d'ici.
     *******************************************/
    int temp(0),cnt(0);
    for (int i = debut; i <= fin; ++i)
    {
        temp = i;
        while (temp>0)
        {
            if (temp%3 ==0)
            {
                temp += 4;
            }
            else  if (temp % 4 == 0)
            {
                temp /= 2;
            }
            else
            {
                temp -= 1;
            }
            cnt++;
        }
        cout << i << " -> " << cnt << endl;
        cnt = 0;
    }

     /*******************************************
      * Ne rien modifier apres cette ligne.
      *******************************************/

    return 0;
}

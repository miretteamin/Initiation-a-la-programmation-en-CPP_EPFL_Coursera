#include <iostream>
#include <string>
#include<array>
#include<vector>
using namespace std;


int main()
{
    string s = "aba";
    long cnt = 0, y = (10 / s.size());
    float anb = count(s.begin(), s.end(), 'a');
    float x = (anb / s.size());
    for (int i = 0; i < 10 % s.size(); ++i)
    {
        if (s[i] == 'a') ++cnt;
    }
    cout << x*y;
    cnt += x * y;
    cout << cnt;
	return 0;
}
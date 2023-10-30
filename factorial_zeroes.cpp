#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int fives = 0;
    for (int i = n; i > 0; i--)
    {
        int temp2 = i;
        while (temp2 != 0)
        {
            if (temp2 % 5 == 0)
            {
                fives++;
                temp2 /= 5;
            }
            else
            temp2=0;
        }
    }
    cout << fives;
}
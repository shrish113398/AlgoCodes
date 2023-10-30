#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], c[n], r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = 0;
        while (a[i] != 0)
        {
            r[i] = a[i] % 10;
            a[i] /= 10;
            if (r[i] == 4)
            {
                c[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int diff = a[1] - a[0];
    int len = 2, an = 2;
    for (int i = 2; i < n; i++)
    {
        if (diff == a[i] - a[i - 1])
        {
            len++;
        }
        else
        {
            diff = a[i] - a[i - 1];
            len = 2;
        }
        an = max(an, len);
    }
    cout << an;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s[n];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == "yes" || s[i] == "Yes" || s[i] == "yEs" || s[i] == "yeS" || s[i] == "YEs" || s[i] == "YeS" || s[i] == "yES"|| s[i] == "YES")
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
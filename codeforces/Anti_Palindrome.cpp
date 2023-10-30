#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    set<char> ch;
    int odds = 0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        ch.insert(s[i]);
    }
    if (mp[s[0]] == n && n%2!=0) 
    {
        cout << "2" << endl;
    }
    else
    {
        for (auto it = ch.begin(); it != ch.end(); it++)
        {
            if (mp[*it] % 2 != 0)
            {
                odds++;
            }
        }
        if (odds == 1)
        {
            cout << "1" << endl;
        }
        else if (odds == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
}

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
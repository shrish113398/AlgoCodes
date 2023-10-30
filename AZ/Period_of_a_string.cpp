#include <bits/stdc++.h>
using namespace std;

#define int long long

int abc = 1;
int pi[100005];

void prefix(string s)
{
    int n = s.size();
    pi[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Test case #" << abc++ << "\n";
        int n;
        cin >> n;
        string s;
        cin >> s;
        prefix(s);
        for (int i = 1; i < n; ++i)
        {
            if ((i + 1) % (i + 1 - pi[i]) == 0 && (i + 1) / (i + 1 - pi[i]) > 1)
            {
                cout << i + 1 << " " << (i + 1) / (i + 1 - pi[i]) << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
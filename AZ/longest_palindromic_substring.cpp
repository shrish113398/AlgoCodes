#include <bits/stdc++.h>
using namespace std;
vector<int> p;

string build(string s)
{
    string q;
    for (auto v : s)
    {
        q += string("#") + v;
    }
    q += "#";
    return q;
}

void manacher(string s)
{
    int n = s.length();
    p.resize(n);
    p.assign(n, 1);
    int l = 1, r = 1;
    for (int i = 0; i < n; i++)
    {
        p[i] = max(0, min(r - i, p[l + r - i]));
        while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    string tst;
    while (t--)
    {

        string s;
        cin >> s;
        tst = build(s);
        manacher(tst);
        auto it = max_element(p.begin(), p.end());
        auto a = it - p.begin();
        int len = *it - 1;
        int start = a / 2 - len / 2;
        cout << s.substr(start, len) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

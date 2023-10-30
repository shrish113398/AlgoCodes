#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[11][11];
int h, w;

ll solve(int i, int j, unordered_set<int> &vis)
{
    if (i < 0 || j < 0 || i == h || j == w || vis.find(a[i][j]) != vis.end())
        return 0;
    if (i == h - 1 && j == w - 1)
    {
        return 1;
    }
    ll val = 0LL;
    vis.insert(a[i][j]);
    val = solve(i + 1, j, vis);
    val += solve(i, j + 1, vis);
    vis.erase(a[i][j]);
    return val;
}

int main()
{
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == a[h - 1][w - 1])
        cout << "0";
    else
    {
        unordered_set<int> vis;
        cout << solve(0, 0, vis);
    }
    return 0;
}
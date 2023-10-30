#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int n, k;
int cnt = 0;
vector<int> cur;
vector<vector<int>> all;
map<int, int> mp;
void rec(int lvl)
{
    if (lvl == n)
    {
        cnt++;
        if (cnt == k)
        {
            for (auto j : cur)
            {
                cout << j << " ";
            }
        }
        all.push_back(cur);
        return;
    }
    for (auto v : mp)
    {
        if (v.second != 0)
        {
            mp[v.first]--;
            cur.push_back(v.first);
            rec(lvl + 1);
            cur.pop_back();
            mp[v.first]++;
        }
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        x=i+1;
        mp[x]++;
    }
    rec(0);
}
int main()
{
    IOS
    solve();
    return 0;
}
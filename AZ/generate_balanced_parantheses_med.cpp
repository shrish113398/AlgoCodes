#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n, k;
vector<int> arr;
vector<char> curr;
map<char, int> mp;
vector<vector<int>> ans;
int co = 0;
int cc = 0;
map<int, int> depth;

void rec(int level)
{
    if (level == n && depth[k] > 0 && depth[k + 1] == 0)
    {
        for (auto c : curr)
            cout << c;
        cout << endl;
    }
    for (auto v : mp)
    {
        if ((co > 0 && v.first == ')' && v.second != 0) || (v.first == '(' && v.second != 0))
        {
            mp[v.first]--;
            curr.push_back(v.first);
            if ((v.first) == '(')
            {
                co++;
                depth[co]++;
            }
            else
            {
                co--;
                depth[co]++;
            }
            rec(level + 1);
            if ((v.first) == '(')
            {
                depth[co]--;
                co--;
            }
            else
            {
                depth[co]--;
                co++;
            }
            curr.pop_back();
            mp[v.first]++;
        }
    }
}

void solve()
{
    cin >> n >> k;
    int x = (n / 2);
    mp['('] = x;
    mp[')'] = x;
    rec(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}
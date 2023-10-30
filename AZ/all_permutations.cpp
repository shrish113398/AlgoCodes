#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int n;
vector<int> cur;
vector<vector<int>> all;
map<int, int> mp;
void rec(int lvl)
{
    if (lvl == n)
    {
        // cout<<lvl<<endl;
        for (int i = 0; i < cur.size(); i++)
        {
            cout<<cur[i]<<" ";
        }
        cout<<endl;
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    rec(0);
}
int main()
{
    IOS
    int count=0;
    solve();
    // for(auto i:all){
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //     count++;
    // }
    return 0;
}
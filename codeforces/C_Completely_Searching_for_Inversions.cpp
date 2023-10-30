#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int cntone = 0;
int ans = 0;
int mod = 998244353;

void dfs(int x, vector<vector<pair<int, int>>> v, vector<int> vis)
{
    vis[x] = 1;
    for (int j=0;j<v[x].size();j++)
    {
        int f = v[x][j].first;
        int s = v[x][j].second;
        // if (!vis[f])
        // {
        //     z.push_back(s);
        //     dfs(f, v, z, vis);
        //     cout<<f<<" "<<s<<" ";
        // }
        // cout<<endl;
        //cout<<f<<" "<<s<<endl;
        if (vis[f]==0)
        {
            // z.push_back(s);
            if(s == 0){
                ans += cntone;
                ans %= mod;
            }
            else{
                cntone++;
            }
            //cout<<s<<" ";
            dfs(f,v,vis);
        }
        else return;
        
    }
}
int main()
{
    IOS int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y, z;
            cin >> y >> z;
            y--;
            v[i].push_back(make_pair(y, z));
        }
    }
    vector<int> vis(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<":"<<endl;
    //     for (auto j: v[i])
    //     {
    //         cout<<j.first<<" "<<j.second<<endl;
    //     }
    // }
    dfs(0, v, vis);
    int count=0;
    cout<<endl;
    // for (int i = 0; i < z.size(); i++)
    // {
    //     cout<<z[i]<<" ";
    // }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
int p = 1e9 + 7;
int n, m, q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vvi g;
vi vis, comp;
int num_count = 0;
bool is_cycle = 0;

void dfs(int node, int count)
{
    vis[node] = count;
    for (auto v : g[node])
    {
        // if(v==node)continue;
        if (!vis[v])
        {
            dfs(v, count);
        }
    }
}

void solve()
{
    cin >> n >> m >> q;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    comp.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num_count++;
            dfs(i, num_count);
        }
    }
    for (auto x : vis)
    {
        // cout<<x<<" ";
        comp[x]++;
    }
    // cout<<endl;
    // for(auto x:comp){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    while (q--)
    {
        int a, x, y;
        cin >> a;
        if (a == 1)
        {
            cin >> x;
            cout << comp[vis[x]] << endl;
        }
        else
        {
            cin >> x >> y;
            if (vis[x] == vis[y])
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    solve();
    return 0;
}
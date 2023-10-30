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
void dfs(int node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
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
            dfs(i);
        }
    }
    cout << num_count - 1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
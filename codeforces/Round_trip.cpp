#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
int p = 1e9 + 7;
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vvi g;
vi arr, col, parent;
bool is_cycle = 0;
void dfs(int node, int par)
{
    parent[node] = par;
    col[node] = 2;
    for (auto v : g[node])
    {
        if (v == parent[node])
            continue;
        if (col[v] == 1)
        {
            dfs(v, node);
        }
        else if (col[v] == 2)
        {
            is_cycle = 1;
        }
    }
    col[node] = 3;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }
    if (is_cycle == 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    solve();
    return 0;
}
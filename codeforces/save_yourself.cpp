#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
using ii = pair<int, int>;
#define F first
#define S second

int n, m;
vector<vector<char>> arr;
vector<vector<int>> Adis; // sortest path for the person to reach any node
vector<vector<int>> Mdis; // will give distance of monster from node which is closest to node

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check_bfs(ii pos)
{
    int x = pos.first;
    int y = pos.second;
    if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#')
        return 1;
    else
        return 0;
}

void bfs(ii st)
{
    Adis.assign(n, vector<int>(m, mod));
    Adis[st.F][st.S] = 0;

    queue<ii> q;
    q.push(st);

    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int curd = Adis[cur.F][cur.S];
        // traversing neighbour of curr
        for (int k = 0; k < 4; k++)
        {
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if (check_bfs(neigh))
            {
                if (Adis[neigh.F][neigh.S] > curd + 1)
                {
                    Adis[neigh.F][neigh.S] = curd + 1;
                    q.push(neigh);
                }
            }
        }
    }
}

void solve()
{
    ii st;
    cin >> n >> m;

    arr.assign(n, vector<char>(m, '.'));
    Mdis.assign(n, vector<int>(m, mod));

    queue<ii> mons;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'M')
            {
                mons.push({i, j});
                Mdis[i][j] = 0;
            }
        }
    }
    bfs(st); // initialise Adis 2D array

    // running bfs on mons to initialise Mdis array
    while (!mons.empty())
    {
        ii curr = mons.front();
        mons.pop();
        for (int k = 0; k < 4; k++)
        {
            ii neigh = {curr.F + dx[k], curr.S + dy[k]};
            if (check_bfs(neigh))
            {
                if (Mdis[neigh.F][neigh.S] > Mdis[curr.F][curr.S] + 1)
                {
                    Mdis[neigh.F][neigh.S] = Mdis[curr.F][curr.S] + 1;
                    mons.push(neigh);
                }
            }
        }
    }

    int is_psbl = 0;
    int ans = mod;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1))
            {
                // cout<<"Exit:("<<i<<' '<<j<<") -> "<<Adis[i][j]<<' '<<Mdis[i][j]<<'\n';
                if (Mdis[i][j] > Adis[i][j])
                {
                    is_psbl = 1;
                    ans = min(Adis[i][j], ans);
                }
            }
        }
    }
    if (is_psbl)
    {
        cout << "YES\n";
        cout << ans << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
#include <iostream>

using namespace std;
const int N = 1010;
int n, m;

bool grid[N][N];
bool visited[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (valid(x + dx[i], y + dy[i]) && grid[x + dx[i]][y + dy[i]])
        {
            if ((!visited[x + dx[i]][y + dy[i]]))
            {
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {

            if (s[j] == '#')
            {
                grid[i][j] = false;
            }
            else
                grid[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
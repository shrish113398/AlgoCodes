#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int ans = 0;
int m, n;

bool prime(int i)
{
    for (int j = 2; j * j <= i; ++j)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}

bool check(int i)
{
    if (i < m || i > n || !prime(i))
        return false;
    return true;
}

void rec(int a, int b, int c)
{
    if ((a * c + b) > n)
        return;
    if (check(a * c + b))
        ans++;
    for (int x = 0; x < 10; ++x)
    {
        if (check((a * 10 + x) * c + b))
            ans++;
    }
    for (int y = 0; y < 10; y++)
    {
        rec((a * 10 + y), (y * c + b), c * 10);
    }
}

void solve()
{
    cin >> m >> n;
    for (int i = 2; i < 10; ++i)
    {
        if (check(i))
        {
            ans++;
        }
    }
    rec(1, 1, 10);
    rec(3, 3, 10);
    rec(5, 5, 10);
    rec(7, 7, 10);
    rec(9, 9, 10);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<int> a(60);
int cnt = 0;
double l = pow(10, -6);

void solve()
{
    long long n;
    int msb = 63;
    cin >> n;
    for (int i = 63; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
    if (n < 0)
    {
        cout << 63 << endl;
    }
    else if (n == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << int(__lg(n)) << endl;
    }
    if (n == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << __builtin_ctzll(n) << endl;
    }
    if (__builtin_popcount(n) == 1 && n != 1)
    {
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
    if (n == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (1ll << __builtin_ctzll(n)) << endl;
    }
    if (n <= 1)
    {
        cout << 2 << endl;
    }
    else
    {
        int a = __builtin_clzll(n - 1);
        cout << (1ll << (64 - a)) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
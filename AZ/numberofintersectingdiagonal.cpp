#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define mod 1000000007
const int size = 1000002;

// int arr[size];

int bin_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

inline int mul(int a, int b)
{
    return (a * b) % mod;
}

void solve()
{
    int N;
    cin >> N;
    int answer = mul(N, N - 1);
    answer = mul(answer, N - 2);
    answer = mul(answer, N - 3);
    answer = mul(answer, bin_pow(24, mod - 2));
    if (answer < 0)
        answer += mod;
    cout << answer % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
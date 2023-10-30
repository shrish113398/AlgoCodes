#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long 
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (q--)
    {
        int sum = 0;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int i = l; i <= r; i++)
        {
            sum = sum % mod + ((arr[i])%mod * (i - l + 1)%mod) % mod;
            sum=sum%mod;
        }
        if (sum < 0)
        {
            cout << sum + mod << endl;
        }
        else
            cout << sum << endl;
    }

    return 0;
}
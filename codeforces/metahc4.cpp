#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve(int t)
{
    int n;
    cin >> n;
    vector<char> arrr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrr[i];
    }
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = arrr[i] - '0';
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;

        for (int j = temp - 1; j < n; j += temp)
        {
            arr[j] = 1 - arr[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            ans++;
            for (int j = i; j < n; j += i + 1)
            {
                arr[j] = 1 - arr[j];
            }
        }
    }

    cout << "Case #" << t << ": " << ans << endl;
}

int main()
{
    IOS

    int t;
    cin >> t;
    int cnt = 1;
    while (t)
    {

        solve(cnt);
        cnt++;
        t--;
    }
    return 0;
}
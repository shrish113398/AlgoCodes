#include <bits/stdc++.h>

#define ll long long int
#define f first
#define s second
#define pb push_back
#define vi vector<int>
const int mod = 1e9 + 7;

using namespace std;

void solve(int t)
{
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                arr.push_back(i);
                n /= i;
            }
        }
    }

    if (n != 1)
        arr.push_back(n);
    ll sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    if (sum > 41)
    {
        cout << "Case #" << t << ": " << -1 << endl;
        return;
    }

    int check = 41 - sum;

    for (int i = 1; i <= check; i++)
    {
        arr.push_back(1);
    }

    cout << "Case #" << t << ": " << arr.size() << " ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return;
}

int main()
{

    int t;
    cin >> t;
    int count = 1;
    while (t)
    {

        solve(count);
        count++;

        t--;
    }
    return 0;
}
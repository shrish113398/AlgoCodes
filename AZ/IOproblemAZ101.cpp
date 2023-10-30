#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double m;
        cin >> m;
        int p = (int)m;
        double q = m - p;
        cout << "n=" << n << endl;
        cout << "p=" << p << endl;
        q *= 1000000000;
        int q1 = round(q);
        while (q1 % 10 == 0)
        {
            q1 /= 10;
        }

        cout << "q=" << q1 << endl;
        cout << int(q1 + n) << "." << int(n + p) << endl;
    }
    return 0;
}
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
        int n, m, p;
        cin >> n >> m >> p;
        for (int i = 0; i < m * 3 + 1; i++)
        {
            cout << "*";
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {

            cout << "*";

            for (int i = p; i > 0; i--)
            {
                cout<<".";
            }
            for (int i = j; i < p-1; i++)
            {
                cout<<".";
            }
            
            for (int i = 0; i < m * 3 + 1; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
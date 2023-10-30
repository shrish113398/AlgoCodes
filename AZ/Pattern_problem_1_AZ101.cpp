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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m*3+1; i++)
        {
            cout << "*";
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {

            cout << "*";
            for (int i = 0; i < m; i++)
            {
                cout << "..*";
            }
            cout << endl;
            cout << "*";
            for (int i = 0; i < m; i++)
            {
                cout << "..*";
            }
            cout << endl;
            for (int i = 0; i < m*3+1; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}
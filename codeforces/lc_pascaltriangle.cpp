#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void printpascal(int n)
{
    int arr[n][n];
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        arr[0][0] = 1;
        arr[1][1] = 1;
        arr[1][0] = 1;
        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    arr[i][0] = 1;
                    cout << arr[i][j] << " ";
                }
                else if (j == i)
                {
                    arr[i][j] = 1;
                    cout << arr[i][j] << endl;
                }
                else
                {
                    arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                    cout << arr[i][j] << " ";
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    printpascal(n);
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
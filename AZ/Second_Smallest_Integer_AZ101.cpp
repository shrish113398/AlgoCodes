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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int m = 999999;
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < m)
            {
                m = arr[i];
                ind = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] -= m;
        }

        int min = 999999;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0 && arr[i] < min)
            {
                min = arr[i];
            }
        }
        if (m + min >= 999999)
        {
            cout << "-1 ";
        }
        else
        {

            cout << (min + m) << endl;
        }
    }
    return 0;
}
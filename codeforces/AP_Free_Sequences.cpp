#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int flag = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i] - arr[j] == arr[j] - arr[k])
                {
                    flag = 1;
                    cout << "No" << endl;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag==0)
    {
        cout<<"Yes"<<endl;
    }
    
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
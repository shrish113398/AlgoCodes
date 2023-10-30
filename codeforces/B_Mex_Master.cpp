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
    int zeros = 0;
    int pos = 0;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            zeros++;
        }
        else
        {

            if (max < arr[i])
            {
                max = arr[i];
            }
            pos++;
        }
    }
    if (zeros == 0)
    {
        cout << "0" << endl;
    }
    else if (zeros <= pos + 1)
    {
        cout << "0" << endl;
    }
    else
    {
        if (max==1)
        {
            cout<<"2"<<endl;
        }
        else
        {
            cout<<"1"<<endl;
        }
        
        
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
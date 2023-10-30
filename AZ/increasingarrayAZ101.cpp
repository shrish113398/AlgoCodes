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
    {   int q;
        cin >> q;
        int arr[q];
        long long count=0;
        for (int i = 0; i < q; i++)
        {
            cin>>arr[i];
        }
        for (int i = 0; i < q-1; i++)
        {
            if (arr[i+1]<arr[i])
            {
                count=count+(arr[i]-arr[i+1]);
                arr[i+1]=arr[i];
                continue;
            }
            
        }
        
        cout<<count<<endl;
    }
    return 0;
}
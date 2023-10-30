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
    int mx=INT_MAX;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin>>x;
        if (abs(x)<mx)
        {
            mx=abs(x);
        }
        
    }
    cout<<mx;
    return 0;
}
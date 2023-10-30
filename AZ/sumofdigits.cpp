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
        long long int n;
        cin>>n;
        long long int sum=0;
        while (n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        cout<<sum<<endl;
    }
    return 0;
}
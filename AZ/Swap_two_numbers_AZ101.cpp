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
        int A,B;
        cin>>A;
        cin>>B;
        int temp;
        temp=A;
        A=B;
        B=temp;
        cout<<A<<" "<<B<<endl;

    }
    return 0;
}
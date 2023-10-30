#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int x1,y1,x2,y2,man,mat2;
    cin>>x1>>y1>>x2>>y2;
    double euc;
    man=abs(x2-x1);
    mat2=abs(y2-y1);
    euc=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double hat=(double)(man+mat2);
    printf("%0.7f %f",euc,hat);
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
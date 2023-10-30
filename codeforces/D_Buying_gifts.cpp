#include <iostream>
#include <bits/stdc++.h>
#include  <tuple>
#define MIN 1e9+1
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n],b[n];
    int i = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    vector <tuple<int,int,int>> list;
    for(int i=0;i<n;i++)
    {
        list.push_back({a[i],0,i});
    }
    for(int i=0;i<n;i++)
    {
        list.push_back({b[i],1,i});
    }
    sort(list.begin(),list.end());
    int ans = MIN;
    int min = MIN;
    for(int i = 0;i < 2*n-1;i++)
    {
        if((get<2>(list[i])!=get<2>(list[i+1]))){
            min = abs(get<0>(list[i])-get<0>(list[i+1]));
            if(min < ans) ans = min;
        }
    }
    cout << ans << endl;

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

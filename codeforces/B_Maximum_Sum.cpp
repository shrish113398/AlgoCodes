#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n,k; cin >> n >> k;
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
 
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        a[i] += a[i-1];
    }
 
    long long ans = 0;
    for(int j=0;j<=n;j++){
        if((j%2)==0 && j/2 <= k){
            int rem = k-j/2;
            int l = j+1, r = n-rem;
            
            ans = max(ans, a[r]-a[l-1]);
        }
    }
 
    cout << ans << endl;
}
signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
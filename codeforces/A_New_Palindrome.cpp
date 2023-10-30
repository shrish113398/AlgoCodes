#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    string s;
    cin >> s;
    set<char> ch;
    for (int i = 0; i < s.length()-i-1; i++)
    {
        ch.insert(s[i]);
    }
     if(ch.size() >= 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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
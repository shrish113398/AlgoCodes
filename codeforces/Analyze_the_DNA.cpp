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
    int arr[s.length()];
    vector<int> a;
    vector<int> g;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            arr[i] = 1;
            a.push_back(i);
        }
        if (s[i] == 'G')
        {
            arr[i] = -1;
            g.push_back(i);
        }
        if (s[i] == 'T')
        {
            arr[i] = 2;
        }
        else
        {
            arr[i] = -2;
        }
    }
    //for A

    int l=a[0];
    int r=a[1];
    int flag=1;

    while (l<=a[a.size()-1])
    {
        while (r<a.size())
        {
            
        }
        
    }
    
    while (l<=r)
    {
        if (l!=r)
        {
            flag=0;
            break;
            l++;r--;
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
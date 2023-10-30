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
        int q;
        cin>>q;
        int arr[q];
        for (int i = 0; i < q; i++)
        {
            cin>>arr[i];
        }

        unordered_map<int,int> ump;
        for (int i = 0; i < q; i++)
        {
            ump[arr[i]]++;
        }
        for(auto i:ump)
        {
            if (i.second%2!=0)
            {
                cout<<i.first<<endl;
                break;
            }
            
        }
        
        
    }
    return 0;
}
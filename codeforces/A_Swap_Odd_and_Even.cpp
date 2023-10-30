#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS
        string s;
    cin >> s;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (i % 2 == 0)
        {
            char temp=s[i];
            s[i]=s[i+1];
            s[i+1]=temp;
        }
    }
    cout<<s<<endl;
    

    return 0;
}
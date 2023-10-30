#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    int a[test];
    for (int i = 0; i < test; i++)
    {
        int n;
        cin>>n;
        int x[n],y[n];
        for (int j = 0; j < n; j++)
        {
            cin>>x[i];
            cin>>y[i];
        }
        
        
        
        for (int  j = 0;  j< n; j++)
        {
            
            
            a[i]+=x[j]*2+y[j]*2;
        }
        
    }


    for (int i = 0; i < test; i++)
    {
        cout<<a[i];
    }
    
    
}
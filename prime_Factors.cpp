#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "enter a number\n";
    int n;
    cin >> n;
    for (int i = 2; i*i <= n; i++)
    {
        while (n%i==0)
        {
            cout<<i;
            cout<<"\t";
            n/=i;
        }
        
    }
    if (n>=1)
    {
        cout<<n;
    }
    
    
}
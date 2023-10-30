#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],c[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
        c[i]=0;
        while (a[i]!=0)
        {
            c[i]=c[i]*10+a[i]%10;
            a[i]/=10;
        }
        
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<c[i]<<endl;
    }
    
    
    return 0;
}
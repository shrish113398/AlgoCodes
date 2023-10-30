#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],l[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
        l[i]=a[i]%10;
        while (a[i]/10!=0)
        {
            a[i]/=10;
        }
        l[i]+=a[i];
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<l[i]<<endl;
    }
    
    
    return 0;
}
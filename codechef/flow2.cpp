#include <iostream>
using namespace std;
int main()
{
    int n;

    cin>>n;
    int a[n],b[n],r[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
        r[i]=a[i]%b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<r[i]<<endl;
    }
    
    
    return 0;
}
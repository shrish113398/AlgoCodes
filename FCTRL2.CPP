#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],p[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {   
        p[i]=1;
        for (int j = 1; j <=a[i]; j++)
        {
            p[i]*=j;
        }
        
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<p[i]<<endl;
    }
    
       
    return 0;
}
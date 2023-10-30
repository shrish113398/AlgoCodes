#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n],y[n],z[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    for (int  i = 0; i < n; i++)
    {
        if ((x[i]+y[i])>z[i])
        {
             cout<<"TRAIN"<<endl;
        }
        else if ((x[i]+y[i])<z[i])
        {
            cout<<"PLANEBUS"<<endl;
        }
        else
        {
            cout<<"EQUAL"<<endl;
        }
        
    }
    
    
    return 0;
}
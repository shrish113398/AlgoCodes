#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int kx[n],r1x[n],r2x[n],ky[n],r1y[n],r2y[n];
    for (int i = 0; i < n; i++)
    {
            for (int j= 0;j < 3;j++)
            {
                cin>>kx[i];
                cin>>ky[i];
                cin>>r1x[i];
                cin>>r1y[i];
                cin>>r2x[i];
                cin>>r2y[i];
            }
            
    }
    for (int i = 0; i < n; i++)
    {
        if (kx[i]=r1x[i])
        {
            
        }
        
    }
    
    return 0;
}
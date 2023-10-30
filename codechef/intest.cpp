#include <iostream>
using namespace std;
int main()
{
    int n;
    long k;
    cin >> n >> k;
    long t[n];
    for (int i = 0; i < n; i++)
    {
        cin>>t[i];
    }
    int c=0;
    for (int i = 0; i <n; i++)
    {
        if (t[i]%k==0)
        {
            c++;
        }
        
    }
    cout<<c;
    
    
    return 0;
}
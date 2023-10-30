#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin>>s;
    int st=-1,en=-1;
    int i=0,sum=0,j=0;
    while (sum<=s && j<n)
    {
        sum+=a[j];
        j++;

    }
    
    if (s==sum)
    {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while (j<n)
    {
        sum+=a[j];
        while (sum>s)
        {
            sum-=a[i];
            i++;
        }
        st=i+1;
        en=j+1; 
        
    }
    cout<<st<<" "<<en;
    return 0;
}
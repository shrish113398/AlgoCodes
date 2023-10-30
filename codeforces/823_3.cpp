#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        // need to create an array of k integers from 1 to n wwith most number of distinct ai+1 -ai terms
        
        int n,k;
        cin>>k>>n;
        int arr[k];
        arr[k-1]=n;
        int diff=(n-1)/(k-1);
        for (int i = k-2; i >=0; i--)
        {
            arr[i]=arr[i+1]-diff;
        }
        for (int i = 0; i < k; i++)
        {
            cout<<arr[i]<<"  ";
        }
        
        
    }
    return 0;
}


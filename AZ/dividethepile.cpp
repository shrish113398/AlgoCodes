#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int gcd(int a, int b)
{
if (a == 0)
	return b;
return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
int result = arr[0];
for (int i = 1; i < n; i++)
{
	result = gcd(arr[i], result);

	if(result == 1)
	{
	return 1;
	}
}
return result;
}
int main()
{
    IOS int t;
    cin >> t;
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    while (t--)
    {
        int res=findGCD(arr,n);
        if (res==1)
        {
            cout<<"No"<<endl;
        }else cout<<"Yes"<<endl;
        
    }
    return 0;
}

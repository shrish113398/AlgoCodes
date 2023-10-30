#include <iostream>
#include <vector>
using namespace std;
#define MODU 1000000007
int solve()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int product=1;
    for (long long int i = 0; i < n; i++)
    {
        cin>>arr[i];
        product*=arr[i];
        product=product%MODU;
    }
    cout<<product<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
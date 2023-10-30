#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
// double findMedian(vector<int> a,
//                   int n)
// {

//     // If size of the arr[] is even
//     if (n % 2 == 0)
//     {

//         // Applying nth_element
//         // on n/2th index
//         nth_element(a.begin(),
//                     a.begin() + n / 2,
//                     a.end());

//         // Applying nth_element
//         // on (n-1)/2 th index
//         nth_element(a.begin(),
//                     a.begin() + (n - 1) / 2,
//                     a.end());

//         // Find the average of value at
//         // index N/2 and (N-1)/2
//         return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
//     }

//     // If size of the arr[] is odd
//     else
//     {

//         // Applying nth_element
//         // on n/2
//         nth_element(a.begin(),
//                     a.begin() + n / 2,
//                     a.end());

//         // Value at index (N/2)th
//         // is the median
//         return (double)a[n / 2];
//     }
// }

void solve(int t,int tt)
{
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    double ans=0.0;
    double m1=((double)arr[0]+(double)arr[1])/2;
    double m2=((double)arr[n-2]+(double)arr[n-1])/2;
    cout<<"Case #"<<tt-t<<": ";
    if(n==5){
        double n1=((double)arr[0]+(double)arr[1])/2;
        double n2=((double)arr[n-1]+(double)arr[n-3])/2;
        double a1=abs(n1-n2);
        double q1=((double)arr[0]+(double)arr[2])/2;
        double q2=((double)arr[n-1]+(double)arr[n-2])/2;
        double p1=abs(q1-q2);
        cout<<max(p1,a1)<<endl;
    }
    else
    {
        cout<<abs(m1-m2)<<endl;
    }
    
}
int main()
{
    IOS int t;
    cin >> t;
    int tt;
    tt=t;
    while (t--)
    {

        solve(t,tt);
    }
    return 0;
}
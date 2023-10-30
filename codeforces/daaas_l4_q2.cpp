#include <iostream>
using namespace std;
 
int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}
 
int main()
{
    int n, m;
    cout<<"enter the first arrays length : ";
    cin>>n;
    cout<<"enter the second arrays length : ";
    cin>>m;
    int arr1[n];
    int arr2[m];
    cout<<"enter the first arrays elements : ";
    for(int i =0; i<n; i++)cin>>arr1[i];
    cout<<"enter the second arrays  elements : ";
    for(int i = 0; i<m; i++)cin>>arr2[i];
    int k;
    cout<<"enter which element you want : ";
    cin>>k;
    cout << kth(arr1, arr2, arr1 + n, arr2 + m,  k - 1)<<endl;
    return 0;
}
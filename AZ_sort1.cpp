#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0;
    int min = -1;
    cout << "Enter the number of monsters";
    int n;
    cin >> n;
    int a[n], b[n], d[n];
    cout << "Enter Ai and Bi";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << b[i] << endl;
        d[i] = a[i] - b[i];
    }
    int aj=0;
    int bl=0;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (d[i] > min)
        {
            ind = i;
            min=d[i];
        }
    }
    sum=a[ind];
}

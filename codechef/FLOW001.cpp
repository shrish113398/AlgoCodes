#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]>>b[i];
        
        cout << endl;
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }

    return 0;
}
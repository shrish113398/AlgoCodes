#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
        while (c[i]!=0)
        {
             s[i] += c[i] % 10;
            c[i]/=10;
        }
        
    }
    for (int i = 0; i <n; i++)
    {
        cout<<s[i]<<endl;
    }

    return 0;
}
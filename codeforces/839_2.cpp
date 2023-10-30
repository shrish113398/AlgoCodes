#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>> n;
    for (int k = 0; k < n; k++)
    {

        int arr[2][2];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> arr[i][j];
            }
        }
        int c = 0;
        while (c < 4)
        {
            c++;
            if (arr[0][0] < arr[1][0] && arr[0][0]<arr[0][1] && arr[1][1] > arr[1][0] && arr[1][1] > arr[0][1])
            {
                cout << "YES" << endl;
                break;
            }
            else
            {
                int temp = arr[1][0];
                arr[1][0] = arr[1][1];
                arr[1][1] = arr[0][1];
                arr[0][1] = arr[0][0];
                arr[0][0] = temp;
            }
            
            
        }
        if (c == 4)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

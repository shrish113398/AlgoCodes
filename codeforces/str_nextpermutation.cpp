#include <algorithm>
#include <iostream>
using namespace std;
 
int main()
{
    int arr[] = { 1, 2, 3, 4 };
 
    sort(arr, arr + 4);
 
    cout << "The 4! possible permutations with 4 elements:\n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2]<< " " << arr[3] << "\n";
    } while (next_permutation(arr, arr + 4));
 
    cout << "After loop: " << arr[0] << ' '
         << arr[1] << ' ' << arr[2]<< ' ' << arr[3] << '\n';
 
    return 0;
}
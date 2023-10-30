// Kirill wants to weave the very beautiful blanket consisting of n×mn×m of the same size square patches of some colors. He matched some non-negative integer to each color. Thus, in our problem, the blanket can be considered a BB matrix of size n×mn×m consisting of non-negative integers.

// Kirill considers that the blanket is very beautiful, if for each submatrix AA of size 4×44×4 of the matrix BB is true:

// A11⊕A12⊕A21⊕A22=A33⊕A34⊕A43⊕A44,A11⊕A12⊕A21⊕A22=A33⊕A34⊕A43⊕A44,
// A13⊕A14⊕A23⊕A24=A31⊕A32⊕A41⊕A42,A13⊕A14⊕A23⊕A24=A31⊕A32⊕A41⊕A42,
// where ⊕⊕ means bitwise exclusive OR

// Kirill asks you to help her weave a very beautiful blanket, and as colorful as possible!

// He gives you two integers nn and mm.

// Your task is to generate a matrix BB of size n×mn×m, which corresponds to a very beautiful blanket and in which the number of different numbers maximized.

// Input
// The first line of input data contains one integer number tt (1≤t≤10001≤t≤1000) — the number of test cases.

// The single line of each test case contains two integers nn and mm (4≤n,m≤200)(4≤n,m≤200) — the size of matrix BB.

// It is guaranteed that the sum of n⋅mn⋅m does not exceed 2⋅1052⋅105.

// Output
// For each test case, in first line output one integer cntcnt (1≤cnt≤n⋅m)(1≤cnt≤n⋅m) — the maximum number of different numbers in the matrix.

// Then output the matrix BB (0≤Bij<263)(0≤Bij<263) of size n×mn×m. If there are several correct matrices, it is allowed to output any one.

// It can be shown that if there exists a matrix with an optimal number of distinct numbers, then there exists among suitable matrices such a BB that (0≤Bij<263)(0≤Bij<263).

#include <iostream>
#include <bits/stdc++.h>
#include  <tuple>
#define int long long int
#define MIN 1e9+1
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n],b[n];
    int i = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    vector <tuple<int,int,int>> list;
    for(int i=0;i<n;i++)
    {
        list.push_back({a[i],0,i});
    }
    for(int i=0;i<n;i++)
    {
        list.push_back({b[i],1,i});
    }
    sort(list.begin(),list.end());
    int ans = MIN;
    int min = MIN;
    for(int i = 0;i < 2*n-1;i++)
    {
        if((get<2>(list[i])!=get<2>(list[i+1]))){
            min = abs(get<0>(list[i])-get<0>(list[i+1]));
            if(ans < min) ans = min;
        }
    }
    cout << ans << endl;

}

void main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return;
}

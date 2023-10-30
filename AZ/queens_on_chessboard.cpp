// #include <bits/stdc++.h>
// using namespace std;
// #define IOS                  \
//     ios::sync_with_stdio(0); \
//     cin.tie(0);              \
//     cout.tie(0);
// int n,cnt=0;
// vector<int> cur;
// vector<vector<int>> all;
// bool check(int row, int cols)
// {
//     for (int prow = 0; prow < row; prow++)
//     {
//         int pcol=cur[prow];
//         if (pcol==cols|| abs(row-prow)==abs(cols-pcol))
//         {
//             return 0;
//         }

//     }
//     return 1;
// }
// void rec(int lvl)
// {
//     if (lvl == n)
//     {
//         for (auto i : cur)
//         {
//             cout << cur[i] << " ";
//         }
//         cout << endl;
//         all.push_back(cur);
//         cnt++;
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (check(lvl,col))
//         {
//             cur.push_back(col);
//             rec(lvl+1);
//             cur.pop_back();

//         }

//     }
// }
// void solve()
// {
//     cin >> n;
//     rec(0);
// }
// int main()
// {
//     IOS solve();
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
int ans = 0;

char arr[8][8];
int arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1};
bool check(int row, int col)
{
    if (arr[row][col] == '*')
        return false;
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = arr2[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol))
            return false;
    }
    return true;
}
void rec(int level)
{
    if (level == 8)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {

        if (check(level, i))
        {
            arr2[level] = i;
            rec(level + 1);
            arr2[level] = -1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cin >> arr[i][j];
    }

    cout << endl;
    rec(0);
    cout << ans;
    return 0;
}
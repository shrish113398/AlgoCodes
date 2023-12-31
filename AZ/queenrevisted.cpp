#include <stdio.h>
#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

int N, cnt = 0;

void solution(int x, vector<int> &prev);

bool isSafe(int row, int col, int prevr, int prevc)
{
    if (prevc == col)
        return false;
    if (abs(prevr - row) == abs(prevc - col))
        return false;
    if (((abs(prevr - row) == 2) && (abs(prevc - col) == 1)) || ((abs(prevr - row) == 1) && (abs(prevc - col) == 2)))
        return false;

    return true;
}

int solve()
{
    cin >> N;

    vector<int> prev;

    solution(0, prev);

    cout << cnt << endl;
}

void solution(int row, vector<int> &prev)
{
    if (row == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        bool canKeep = true;
        for (int j = 0; j < prev.size(); j++)
        {
            if (!isSafe(row, i, j, prev[j]))
            {
                canKeep = false;
            }
        }

        if (canKeep)
        {

            prev.emplace_back(i);
            solution(row + 1, prev);
            prev.pop_back();
        }
    }
}

int main()
{
    solve();
}
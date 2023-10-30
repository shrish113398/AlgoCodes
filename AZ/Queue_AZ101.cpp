#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int q;
    cin >> q;
    queue<int> que;
    while (q--)
    {
        string operation;
        cin >> operation;
        if (operation == "add")
        {
            int x;
            cin >> x;
            que.push(x);
        }
        else if (operation == "remove")
        {
            if (!que.empty())
            {
                que.pop();
            }
        }
        else if (operation == "print")
        {
            if (que.empty())
            {
                cout << "0" << endl;
            }
            else
            {
                cout << que.front() << endl;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

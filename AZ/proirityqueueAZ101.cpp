#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (s == "add")
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (s == "remove")
        {
            if (!pq.empty())
            {
                pq.pop();
            }
        }
        else if (s == "print")
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
            }
        }
    }
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
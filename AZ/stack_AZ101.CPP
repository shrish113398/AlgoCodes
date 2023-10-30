#include <iostream>
#include <stack>
using namespace std;

int solve()
{
    int q;
    cin >> q;

    stack<int> s;
    while (q--)
    {
        string op;
        cin >> op;

        if (op == "add")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == "remove")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (op == "print")
        {
            if (s.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << s.top() << endl;
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

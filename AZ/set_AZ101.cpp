#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        set<int> set1;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                int x;
                cin >> x;
                set1.insert(x);
            }
            else if (s == "erase")
            {
            
                int x;
                cin >> x;
                auto it = set1.find(x);
                if (it != set1.end())
                {
                    set1.erase(x);
                }
            }
            else if (s == "find")
            {
                int x;
                cin >> x;
                auto it = set1.find(x);
                if (it == set1.end())
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "YES\n";
                }
            }
            else if (s == "print")
            {
                for (auto it = set1.begin(); it != set1.end(); ++it)
                    cout << ' ' << *it;

                cout << endl;
            }
            else if (s == "empty")
            {
                set1.clear();
            }
        }
    }
    return 0;
}
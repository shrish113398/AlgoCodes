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
        deque<int> d;
        vector<int> v1, v2;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "insertback")
            {
                int x;
                cin >> x;
                d.push_back(x);
                v1.push_back(x);
            }
            else if (s == "eraseback")
            {
                if (!d.empty())
                {
                    d.pop_back();
                    v1.pop_back();
                }
            }
            else if (s == "insertfront")
            {
                int x;
                cin >> x;
                d.push_front(x);
                v2.push_back(x);
            }
            else if (s == "erasefront")
            {
                if (!d.empty())
                {
                    d.pop_front();
                    v2.pop_back();
                }
            }
            else if (s == "printfront")
            {
                if (!d.empty())
                {
                    cout << d.front() << endl;
                }
            }
            else if (s == "printback")
            {
                if (!d.empty())
                {
                    cout << d.back() << endl;
                }
            }
            else if (s == "print")
            {
                int x;
                cin >> x;
                int l1 = v1.size();
                if (!d.empty())
                {

                    if (x < l1)
                    {
                        cout << v1[l1 - 1 - x] << endl;
                    }
                    else
                    {
                        x -= l1;
                        cout << v2[x] << endl;
                    }
                }
                else
                {
                    cout<<"0\n";
                }
                
            }
        }
    }
    return 0;
}
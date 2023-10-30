#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else //  ')'
        {
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else st.push(s[i]);
        }
    }
    cout << st.size() << endl;
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
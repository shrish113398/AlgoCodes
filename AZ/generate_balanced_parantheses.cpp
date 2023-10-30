#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int n;
map<char, int> mp;
vector<char> curr;
stack<int> st;
bool isBalanced()
{
    // Initialising Variables
    bool flag = true;
    int count = 0;
 
    // Traversing the Expression
    for (int i = 0; i < n; i++) {
 
        if (curr[i] == '(') {
            count++;
        }
        else {
            // It is a closing parenthesis
            count--;
        }
        if (count < 0) {
            // This means there are
            // more Closing parenthesis
            // than opening ones
            flag = false;
            break;
        }
    }
 
    // If count is not zero,
    // It means there are more
    // opening parenthesis
    if (count != 0) {
        flag = false;
    }
 
    return flag;
}
// void PrintStack(stack<int> s)
// {
//     // If stack is empty then return
//     if (s.empty())
//         return;

//     int x = s.top();

//     // Pop the top element of the stack
//     s.pop();

//     // Recursively call the function PrintStack
//     PrintStack(s);

//     // Print the stack element starting
//     // from the bottom
//     cout << x << " ";

//     // Push the same element onto the stack
//     // to preserve the order
//     s.push(x);
// }

void rec(int lvl)
{
    // if (lvl == n)
    // {
    //     for (auto i : curr)
    //     {
    //         // if (curr[i] == 1)
    //         // {
    //         //     cout << "(";
    //         // }
    //         // else
    //         // {
    //         //     cout << ")";
    //         // }

    //         cout<<curr[i];
    //     }
    //     cout << endl;
    //     return;
    // }
    // for (auto i : mp)
    // {
    //     if (i.second != 0)
    //     {
    //         mp[i.first]--;
    //         curr.push_back(i.first);
    //         rec(lvl + 1);
    //         curr.pop_back();
    //         mp[i.first]++;
    //     }
    // }
    if (lvl == n)
    {
        // cout<<lvl<<endl;
        // if (st.empty())
        // {
        // PrintStack(st);
        if (isBalanced())
        {
            for (int i = 0; i < curr.size(); i++)
            {
                cout << curr[i];
            }
            cout << endl;
        }
        // }
        // else
        // {
        //     cout << "invalid" << endl;
        // }

        return;
    }
    for (auto v : mp)
    {
        if (v.second != 0)
        {
            mp[v.first]--;
            curr.push_back(v.first);
            rec(lvl + 1);
            curr.pop_back();
            mp[v.first]++;
        }
    }
}
void solve()
{
    cin >> n;
    mp['('] += n / 2;
    mp[')'] += n / 2;
    rec(0);

    // cout << endl;
    // for (auto i : mp)
    // {
    //     cout << i.first << "->" << i.second << endl;
    // }
    // cout << endl;
}
int main()
{
    IOS
    solve();
    return 0;
}
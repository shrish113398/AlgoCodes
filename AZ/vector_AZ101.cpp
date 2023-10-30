#include <iostream>
#include <vector>
using namespace std;
int solve(){
    int Q;
    cin >> Q;
    vector<string> v;
    while (Q--)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            string x;
            cin >> x;
            v.emplace_back(x);
        }
        else if (op == "remove")
        {
            if (!v.empty())
                v.pop_back();
        }
        else if (op == "print")
        {
            int x;
            cin >> x;
            if (x >= 0 && x < (int)v.size())
                cout << v[x] << endl;
            else
                cout << "0" << endl;
        }
        else
        {
            v.clear();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    
    return 0;
}
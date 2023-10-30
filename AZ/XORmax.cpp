#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

struct node
{
    int cnt;
    node *child[2];
    int value;
    node()
    {
        child[0] = NULL;
        child[1LL] = NULL;
        cnt = 0;
        value = -1LL;
    }
};
struct trie
{
    node *root;
    trie()
    {
        root = new node();
    }
    void insert(int n)
    {
        node *curr = root;
        for (int i = 32; i >= 0; i--)
        {
            curr->cnt++;
            int x = (n & (1LL << i)) ? 1LL : 0;
            if (curr->child[x] == NULL)
                curr->child[x] = new node();
            curr = curr->child[x];
        }
        curr->cnt++;
        curr->value = n;
    }
    void remove(int n)
    {
        node *curr = root;
        for (int i = 32; i >= 0; i--)
        {
            curr->cnt--;
            int x = (n & (1LL << i)) ? 1LL : 0;
            curr = curr->child[x];
        }
        curr->cnt--;
        if (curr->cnt == 0)
            curr->value = -1LL;
    }

    int query(int n)
    {
        node *curr = root;
        int ans = 0;
        bool con = false;
        if (n == 3)
            con = true;
        for (int i = 32; i >= 0; i--)
        {
            int x = (n & (1LL << i)) ? 1LL : 0;
            if (curr->child[!x] != NULL and curr->child[!x]->cnt != 0)
            {
                ans |= (1LL << i);
                curr = curr->child[!x];
            }
            else
            {
                curr = curr->child[x];
            }
        }
        return ans;
    }
};

void solve()
{
    trie tt;
    int n, q;
    cin >> n;
    tt.insert(0);
    while (n--)
    {
        char c;
        cin >> c >> q;
        if (c == '+')
        {
            tt.insert(q);
        }
        else if (c == '-')
        {
            tt.remove(q);
        }
        else if (c == '?')
        {
            int ans = tt.query(q);
            cout << ans << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin>>_t;while(_t--)
    solve();

    return 0;
}
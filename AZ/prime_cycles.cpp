#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> avl;
vector<int> prime(40, 0);
void init()
{
    prime[2] = 1;
    prime[3] = 1;
    prime[5] = 1;
    prime[7] = 1;
    prime[11] = 1;
    prime[13] = 1;
    prime[17] = 1;
    prime[19] = 1;
    prime[23] = 1;
    prime[29] = 1;
    prime[31] = 1;
    prime[37] = 1;
}
void rec(int level, int prev)
{
    if (level == n)
    {
        if (prime[prev + 1])
            ans++;
        return;
    }
    int par = prev % 2;
    for (int i = 1 + par; i <= n; i += 2)
    {
        if (avl[i] && prime[prev + i])
        {
            avl[i] = 0;
            rec(level + 1, i);
            avl[i] = 1;
        }
    }
}
int main()
{
    init();
    cin >> n;
    if (n % 2)
    {
        cout << 0;
        return 0;
    }
    avl.resize(n + 1, 1);
    avl[1] = 0;
    rec(1, 1);
    cout << ans;
}
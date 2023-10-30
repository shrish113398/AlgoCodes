#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
    bool replace(multiset<int> &s, int &curSum)
{
    vector<int> t;
    for(auto item: s){
        t.push_back(item);
    }
    int sum= curSum;
    int n = t.size();
    for(int i= n-1; i>=1; i--){
        for(int j= i-1; j>=0; j--){
            sum = curSum;
            sum-= (t[i]+t[j]);
            sum+= (t[i]*t[j]);
            if(sum<=41){
                s.erase(s.find(t[i]));
                s.erase(s.find(t[j]));
                s.insert(t[i]*t[j]);
                curSum =sum;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> tempArray;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                tempArray.push_back(i);
                n /= i;
            }
        }
    }

    if (n != 1)
        tempArray.push_back(n);
    multiset<int> s;
    int curSum = 0;
    for (long long i = 0; i < tempArray.size(); i++)
    {
        s.insert(tempArray[i]);
        curSum += tempArray[i];
    }
    if(curSum>41){
        cout<<"-1"<<endl;
        return;
    }
    while (tempArray.size() > 1)
    {
        if(!replace(s,curSum))break;
    }
    cout<<s.size()+ 41 - curSum<<" ";
    for(auto item: s){
        cout<<item<<" ";
    }
    int check = 41 - curSum;

    for(int i = 1 ; i<= check ; i++){
        cout<<"1"<<" ";
    }
    cout<<endl;
    return;
}

signed main()
{
    IOS

    long long t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
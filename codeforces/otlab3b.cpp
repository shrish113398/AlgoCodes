#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > generateCombinations(int startIndex, int k, int n)
{
    if (k == 0)
    {
        return vector<vector<int> >(1, vector<int>());
    }

    vector<vector<int> > combinations;
    for (int i = startIndex; i <= n - k; ++i)
    {
        vector<vector<int> > subCombinations = generateCombinations(i + 1, k - 1, n);
        for(int j = 0; j<subCombinations.size(); j++)
        {
            subCombinations[j].insert(subCombinations[j].begin(), i);
            combinations.push_back(subCombinations[j]);
        }
    }

    return combinations;
}
int main()
{
    cout<<"Enter n and m where (n==rows) and (m==columns) : "<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"Enter Matrix : "<<endl;
    vector<vector<double> > inp(n,vector<double> (m));
    vector<double> b(n);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>inp[i][j];
        }
    }
    cout<<"Enter constant-term of every equation : "<<endl;
    for(int i = 0; i<n; i++)
        cin>>b[i];
    cout<<endl;
    cout<<"Enter the coefficients of the equation to be minimized : ";
    vector<double> c(m);
    for(int i = 0; i<m; i++)
        cin>>c[i];
    vector<vector<int> > comb = generateCombinations(0,n,m);
    vector<vector<double> > ans;
    double mini = 1e5;
    cout<<"Feasible Solutions : "<<endl;
    for(int i = 0; i<comb.size(); i++)
    {
        vector<double> sol(m,0);
        vector<vector<double> > mat(n,vector<double> (n));
        for(int u = 0; u<n; u++)
        {
            for(int v = 0; v<comb[i].size(); v++)
            {
                mat[u][v] = inp[u][comb[i][v]];
            }
        }
        vector<double> x1(n,3);
        int cnt = 1000,check = 1,failure = 0;
        while(cnt--)
        {
            for(int i = 0; i<n; i++)
            {
                double sum = 0;
                for(int j = 0; j<n; j++)
                {
                    if(j==i)
                        continue;
                    sum+=(mat[i][j]*(x1[j]));
                }
                x1[i] = (b[i]-sum)/mat[i][i];
                if(x1[i]>=1e5 || x1[i]<-1e5)
                    failure = 1;
            }
        }
        for(int v = 0; v<comb[i].size(); v++)
            sol[comb[i][v]] = x1[v];
        int feasibilitycheck = 1,degeneratecheck = 0;
        for(int i = 0; i<sol.size(); i++)
        {
            if(sol[i]<0)
                feasibilitycheck = 0;
            if(sol[i]==0)
                degeneratecheck++;
        }
        if(failure)
        {
            continue;
        }
        if(feasibilitycheck)
        {
            for(int i = 0; i<m; i++)
                cout<<sol[i]<<" ";
            cout<<endl;
            double ans = 0;
            for(int i = 0; i<m; i++)
                ans+=(c[i]*sol[i]);
            mini = min(mini,ans);
        }

    }
    cout<<"Minimum Value of the equation to be minimised is : "<<mini<<endl;
}
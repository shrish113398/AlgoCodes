#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int A[m+1][n+2];
    int a=0,b=0;//no.of extra variable;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(j==n)
            {
                int c;
                cout<<"Operator('='->0,'>'->1,'<'->2)"<<endl;
                cin>>c;
                A[i][n+1]=c;
                if(c==0)
                {
                    a++;
                    b++;
                }
                else if(c==1)
                {
                    a+=2;
                    b++;
                }
                else
                {
                    a++;
                    b++;
                }
                cin>>A[i][j];
                continue;
            }
            cin>>A[i][j];
        }
    }
    int B[m+2][a+n+2];//Intialize it to 0;
    memset(B,0,sizeof(B));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;++j)
        {
            B[i][j]=A[i][j];
        }
    }
    int c=n;
    vector<vector<int>>basis(b,vector<int>(m,0));
    b=0;
    for(int i=0;i<m;++i)
    {
        if(A[i][n+1]==0)
        {
            B[i][c]=1;
            basis[i][b]=1;
            b++;
            c++;
        }
        else if(A[i][n+1]==1)
        {
            B[i][c]=-1;
            c++;
            B[i][c]=1;
            basis[i][b]=1;
            b++;
            c++;
        }
        else
        {
            B[i][c]=1;
            c++;
            basis[i][b]=1;
            b++;
        }
    }
    for(int i=0;i<m;++i)
    {
        B[i][c]=A[i][n];
    }
    cout<<"Solution matrix :-"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int  j=0;j<=n+a;++j)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Basis :-"<<endl;
    for(auto i:basis)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
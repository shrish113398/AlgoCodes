#include<bits/stdc++.h>
#include<set>
using namespace std;
#define moving(i,p,q) for(int i=p;i<q;i++)
#define vf vector<float>
#define vvf vector<vector<float>>
#define vi vector<int>
#define vvi vector<vector<int>>
vf guass(vvf coff, vf &b){
    int n = coff.size();

    vf x(n, 0); 
    moving(i,0,10000){
        vf temp = x;
        moving(j,0,n){
            float sum = 0;
            moving(k,0,n){
                if(k!=j){
                    sum += coff[j][k]*x[k];
                }
            }
            temp[j] = (1.0/(coff[j][j]))*(b[j]-sum);
        }
        x = temp;
    }
    moving(i,0,n){
        cout<<x[i]<<" ";
    }
    cout<<"\n";
    return x;
}

int fac(int n){
    if(n == 0 || n==1){
        return 1;
    }

    return n*fac(n-1);
}

bool isFeasible, isDegenerate;


string classify(vvf coff,vf &b, vi poss){
    int m = coff.size();
    int n = coff[0].size();
    set<int> u;
    set<int> nb;
    vvf temp(m);
    for(int i=0; i<poss.size(); i++){
        if(poss[i] == 0){
            for(int k=0; k<m; k++){
                coff[k][i] = 0;
            }
        }
        else{
            u.insert(i);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(coff[i][j]){
                temp[i].push_back(coff[i][j]); 
            }
            
        }
    }
    
    vf ans = guass(temp, b);

    isFeasible = true;
    isDegenerate = false;
    moving(i,0,ans.size()){
        if(ans[i] < 0){
            isFeasible = false;
        }

        if(u.find(i) != u.end() && ans[i] == 0){
            isDegenerate = true;
        }
    }

    if(isFeasible && isDegenerate){
        return "is degenerate and feasible basic solution";
    }

    else if(isFeasible && !isDegenerate){
        return "is Feasible but non degenerate basic solution";
    }

    else if(!isFeasible && isDegenerate){
        return "is Non Feasible but degenerate basic solution";
    }

    else{
        return "is Non Feasible and Non Degenerate basic solution";
    }

}

void solve(vvf coff, vf &b){
    int n = coff[0].size();
    int m = b.size();

    int d = n-m;
    vi poss;

    moving(i,0,n){
        if(i < d){
            poss.push_back(0);
        }
        else{
            poss.push_back(1);
        }
    }   

    int t = (fac(n)/(fac(d)*fac(m))); // t: total solutions

    cout<<classify(coff, b, poss)<<"\n";


    moving(i,0,t-1){
        next_permutation(poss.begin(), poss.end());
        cout<<classify(coff, b, poss)<<"\n";
    }

}

int main(){

    int n, m;
    cin>>n>>m;
    vf v(n, 0);
    vvf coff(m, v);
    moving(i,0,m){
        moving(j,0,n){
            cin>>coff[i][j];
        }
    }
    vf b(m);
    moving(i,0,m){
        cin>>b[i];
    }
    solve(coff, b);
    return 0;
}




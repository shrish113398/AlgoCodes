#include<bits/stdc++.h>
// #include<unordered_set>
#include<set>
using namespace std;

vector<float> guass(vector<vector<float> > coff, vector<float> &b){
    int n = coff.size();

    vector<float> x(n, 0); // initial guess
    // cout<<"n = "<<n<<"\n";

    for(int i=0; i<10000; i++){
        vector<float> temp = x;

        for(int j=0; j<n; j++){
            float sum = 0;

            for(int k=0; k<n; k++){
                if(k!=j){
                    sum += coff[j][k]*x[k];
                }
            }
            
            temp[j] = (1.0/(coff[j][j]))*(b[j]-sum);
        }
        x = temp;
    }

    for(int i=0; i<n; i++){
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


string classify(vector<vector<float> > coff, vector<float> &b, vector<int> poss){
    int m = coff.size();
    int n = coff[0].size();
    set<int> u;
    set<int> nb;

    vector<vector<float> > temp(m);

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
    // cout<<"temp.size() = "<<temp.size()<<"\n";
    // cout<<"temp[0].size() = "<<temp[0].size()<<"\n";
    
    vector<float> ans = guass(temp, b);

    isFeasible = true;
    isDegenerate = false;
    for(int i=0; i<ans.size(); i++){
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

void solve(vector<vector<float> > coff, vector<float> &b){
    int n = coff[0].size();
    int m = b.size();

    int d = n-m;
    vector<int> poss;

    for(int i=0; i<n; i++){
        if(i < d){
            poss.push_back(0);
        }
        else{
            poss.push_back(1);
        }
    }

    int t = (fac(n)/(fac(d)*fac(m))); // t: total solutions

    cout<<classify(coff, b, poss)<<"\n";


    for(int i=0; i<t-1; i++){
        next_permutation(poss.begin(), poss.end());
        cout<<classify(coff, b, poss)<<"\n";
    }

}

int main(){

    int n, m; //n is the no. of variables and m is the number of equations
    // cout<<"Enter number of varibales: ";
    cin>>n>>m;

    vector<float> v(n, 0);
    vector<vector<float> > coff(m, v); //coff represents the coefficient matrix

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>coff[i][j];
        }
    }

    vector<float> b(m);
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    solve(coff, b);
    
    return 0;
}
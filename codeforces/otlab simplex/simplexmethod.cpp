#include<bits/stdc++.h>
using namespace std;
float change(vector<float>&a, vector<float>&b){   // calculating change in value when compared to previous value
    float chng = 0;
    for(int i=0;i<a.size();i++){
        chng += abs(a[i] - b[i]); 
    }
    return chng;                                     
}    

vector<float> GaussSeidelMethod(vector<vector<float> >&A, vector<float>&B, int k, int err, int m, vector<int>&p){
    int n = B.size();

    vector<float>solution(n,0);                           // assuming initial guess as 0 for all input
    
    while(--k){                                   
        vector<float>prevv = solution;                     // prevv array to store solutions of last iteration
        for(int i=0;i<n;i++){
            if(A[i][i] == 0) return {}; 
            solution[i] = B[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                solution[i] -= (A[i][j] * solution[j]);   // Appylying gauss seidel method
            }
            solution[i] /= A[i][i];

            if(abs(solution[i]) > 1e9){ // Matrix is divergent
                return {};                                     
            }
        }
        
        float e = change(prevv,solution);           
        
        if(e < err) break;                       // Break if converges

        for(int i=0;i<n;i++){
            if(abs(solution[i] - prevv[i]) < 1e-8) break;
        }
    } 
    
    for(int i=0;i<n;i++){                       // Checking if equation is satisfied with calculated values
        float x = B[i];
        for(int j=0;j<n;j++){
            x -= A[i][j] * solution[j];
        }
        if(abs(x) > 0.01){
            return {};
        }
    }
    int c = 0;
    vector<float>answer;
    for(int i=0;i<m;i++){
        if(p[i]) answer.push_back(solution[c++]);                      // BASIC VARIABLE
        else answer.push_back(0);                                   // NBV
    } 

    return answer;
}


void prntbfs(vector<vector<float> > A, int m,int n ,vector<string> nbv,vector<string> bv){
    
    for(int i=0;i<n-m;++i){
        string s="x";
        s.append(to_string(i+1));
        int flag=0;
        cout<<s<<" = ";
        for(int j=0;j<n-m;++j){
            
            if(nbv[j]==s){
                cout<<"0 ,";
                flag=1;
                break;
            }
            
        }
        for(int j=0;j<m && flag!=1;++j){
        if(bv[j]==s){
         cout<<A[j][n]<<" ";
         break;
    }}
}}
void prntinttab(vector<vector<float> >&A, int m,int n,vector<string> nbv,vector<string>bv ){
    for(int i=0;i<n-m;++i){
        cout<<"-"<<nbv[i]<<" ";
    }
    cout<<nbv[n-m]<<"\n";
    for(int i=0;i<m+1;++i){
        for(int j=0;j<=n;++j){
            cout<<A[i][j]<<"  ";
            if(j==n-m-1){
                j=n-1;
            }
        }
        cout<<" = "<<bv[i]<<"\n";
    }
}
int minPos(vector<vector<float> >&A, int m,int n ,vector<string> nbv,vector<string>bv){
    int minpos=0;
    for(int i=1;i<n-m;++i){
  
        if(A[m][minpos]>A[m][i]){
            minpos=i;

        }
        
    }
    if(A[m][minpos]<0)
    return minpos;
    else{
        cout<<"\no more iterations possible optimal solution is as follows ";
        prntbfs(A,m,n,nbv,bv);
        cout<<"\n optimal value Z = "<<A[m][n];
        return -1; // *******if no negative elements
    }
}
int pivotrow(vector<vector<float> >&A, int m,int n ,int min){
    int pos=-1;
    for(int i=0; i<m;++i){
        if(A[i][min]>0 && A[i][n]/A[i][min]>=0){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<"\n problem is unbounded \n"; 
        return -1; // unbounded
    }
    for(int i=0;i<m;++i){
        if(A[i][min]>0 && A[i][n]/A[i][min]>=0){
        if(A[pos][n]/A[pos][min]>A[i][n]/A[i][min]){
            pos=i;
        }}

    }
   
    return pos;
   
}
void itrtable(vector<vector<float> >&A, int m,int n ,int x , int y,vector<string>& nbv,vector<string>&bv){
    string s= nbv[y];
    nbv[y]=bv[x];
    bv[x]=s;
    float pvt=A[x][y];
     vector<vector<float> >C(m+1, vector<float>(n+1));
    for(int i=0; i<=m;++i){
        for(int j=0;j<=n;++j){
            if(i==x && j==y){
                C[i][j]=1/pvt;
            }
           else if(i==x && j!=y){
                C[i][j]=A[i][j]/pvt;
            }
            else if(i!=x && j==y){
                C[i][j]=-A[i][j]/pvt;
            }
            else{
                C[i][j]=A[i][j]-(A[i][y]*A[x][j]/pvt);

            }

        }
    }
     for(int i=0; i<=m;++i){
        for(int j=0;j<=n;++j){
            A[i][j]=C[i][j];   
         }
    }
}
int checkopt(vector<vector<float> >&A, int m,int n){
   
    for(int j=0;j<n-m;j++){
            
           if( A[m][j]<0){
            return 0;
           }
        }
        return 1;
}
int main(){
    int m,n,minpos,pvtrow,c;                                        // no. of eqns and variables
    cout<<"Enter no. of eqns to be given ";
    cin>>m;
    cout<<"Enter no. of unknown variables including slack and surplus variables";
    cin>>n;
    vector<vector<float> >A(m+1, vector<float>(n+1));
    vector<float>B(m);
    vector<string> nbv(n-m+1);
    vector<string> bv(m+1);

    cout<<"Enter Augmented matrix A|B: (first coeff of normal variables then slack finally matrix B)  \n";
    cout<<"x1 + x2 +0x3 + s1+ 0s2 =10 to be  written as 1 1 0 1 0 10 \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n+1;j++){
            cin>>A[i][j];   
                                  // entering coeffeicient matrix
        }
        B[i]=A[i][n];                                  // entering RHS matrix B
    }

    cout<<"Enter the maximize function Z (first coeff of normal variables then slack)= \n";
    cout<<"Z= x1 + x2 + 5x3 + 0s1+ 0s2 to be  written as 1 1 5 0 0 \n";
     for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            A[m][j]=-temp;  
                                     // entering coeffeicient matrix
        }
    cout<<"enter constant term in maximize func \n";
    cin>>A[m][n];
    for(int i=0;i<n-m;++i){
        string s="x";
        s.append(to_string(i+1));
        nbv[i]=s;
    }
    nbv[n-m]="1";
    for(int i=0;i<m;++i){
        string s="s";
        s.append(to_string(i+1));
        bv[i]=s;
    }
    bv[m]="Z";
    cout<<"MENU :\n";
    cout<<"1) list of bfs\n";
    cout<<"2) intial simplex table \n";
    cout<<"3) non basic varaiaqbles in initial table \n ";
    cout<<"4) basic variables and min ratio of first iteration \n";
    cout<<"5) simplex table of second iteration \n";
    cout<<"Please enter the option to be chosen ";
    cin>>c;
    switch (c)
    {
    case 1:{ 
            // int i=0;
            //  while(checkopt(A,m,n)!=1){
            // cout<<"\n basic feasible solution at "<<i++<<"th iteration \n";
            // prntbfs(A,m,n,nbv,bv);
            // cout<<"\n objective value Z ="<<A[m][n]<<" ";
            // minpos=minPos(A,m,n);
            // pvtrow=pivotrow(A,m,n,minpos);
            // itrtable(A,m,n,pvtrow,minpos,nbv,bv);
            //  }
            // cout<<"\n optimal solution is as follows and is obtained at "<<i<<"th iteration \n";
            // prntbfs(A,m,n,nbv,bv);
            // cout<<"\n optimal value Z ="<<A[m][n];
                vector<int>permut(n,1);
                for(int i=0;i<n-m;i++) permut[i] = 0;                //  permut[i] = 0 => x[i] is NBV

                vector<vector<float> >c(m, vector<float>(m));    // 'c is temporary matrix
                int cnt = 1;
                do{
                    for(int i=0;i<m;i++){
                        int x = 0;
                        for(int j=0;j<n;j++){                   
                            if(permut[j] == 0) continue;
                            c[i][x++] = A[i][j];                // create temporary copy
                        }
                    }
                    vector<int>p(m);
                    vector<float>tempb(m);
                    vector<vector<float> >tempa(m, vector<float>(m,0));
                    for(int i=0;i<m;i++) p[i] = i;

                    do{
                        for(int i=0;i<m;i++){
                            tempa[i] = c[p[i]];
                            tempb[i] = B[p[i]];
                        } 
                        vector<float>ans = GaussSeidelMethod(tempa,tempb,100000,1e-10,n,permut);  // Guass Seidal Method to calculate solution of the equations
                        if(ans.size()){
                            bool neg = false;
                            cout<<"Solution "<<cnt++<<"=> ";
                            for(int i=0;i<n;++i){
                                cout<<ans[i]<<" ";           // Print
                                if(ans[i] < 0) neg = true;
                            }
                            if(neg) cout<<"Invalid Solution";                
                            cout<<endl;
                            break;
                        }
                    }while(next_permutation(p.begin(),p.end())); //Generate all permuations of matrix
                    
                }while(next_permutation(permut.begin(), permut.end()));   // 'next_permuation' 

                break;

                 }                
        
     case 2:{
            cout<<" You have chosen initial simplex table\n";
             prntinttab(A,m,n,nbv,bv);
             break;
             }
    case 3: {
            cout<<"\n non basic variables in initial table ";
            for(int i=0;i<n-m;++i){
                cout<<nbv[i]<<" , ";

            }
            break; 
             }        
    case 4:
           {minpos=minPos(A,m,n,nbv,bv);
           if(minpos==-1){
            return 0;
           }
            pvtrow=pivotrow(A,m,n,minpos);
            if(pvtrow==-1){
                return 0;
            }
            itrtable(A,m,n,pvtrow,minpos,nbv,bv);
            cout<<"\n basic variables in 1st iteration ";
            for(int i=0;i<m;++i){
                cout<<bv[i]<<", ";
            }
            minpos=minPos(A,m,n,nbv,bv);
            if(minpos==-1){
            return 0;
           }
            pvtrow=pivotrow(A,m,n,minpos);
             if(pvtrow==-1){
                return 0;
            }
            cout<<"\n min ratio after 1st iteration : "<<A[pvtrow][n]/A[pvtrow][minpos];
            break;
           }
    case 5: {
            minpos=minPos(A,m,n,nbv,bv);
            if(minpos==-1){
            return 0;
           }
            pvtrow=pivotrow(A,m,n,minpos);
             if(pvtrow==-1){
                return 0;
            }
            itrtable(A,m,n,pvtrow,minpos,nbv,bv);
            minpos=minPos(A,m,n,nbv,bv);
            if(minpos==-1){
            return 0;
           }
            pvtrow=pivotrow(A,m,n,minpos);
             if(pvtrow==-1){
                return 0;
            }
            itrtable(A,m,n,pvtrow,minpos,nbv,bv);
            cout<<"\n table 2 \n";
            prntinttab(A,m,n,nbv,bv);
            break;
            }
    default: cout<<"choose valid menu item\n";
        break;
    }
    
    return 0;
}
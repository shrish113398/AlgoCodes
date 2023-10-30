#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void prntinttab(vector<float> C,vector<vector<float> >&A,vector<string> V, int m,int n,vector<string> bv,vector<float> CB, vector<float> Z_C,int N,int su){
    cout<<"\tC_j:\t";
    for(int j=0;j<=N;j++){
       cout<<C[j]<<"\t";
        }     
    cout<<"\n CB\t BV \t";
    for(int i=0;i<=N;++i){
          cout<<V[i]<<"\t";
        }  
    cout<<"\n";
     for(int i=0;i<m;i++){
        cout<<CB[i]<<"\t";
        cout<<bv[i]<<"\t";  
        for(int j=0;j<=N;j++){
             
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";                                
    }
    cout<<"Zj-Cj\t\t";
    for(int i=0;i<=N;++i){
        cout<<Z_C[i]<<"\t";
    }

}
int minPos(vector<float> Z_C,int N ){
    int minpos=0;
    for(int i=1;i<N;++i){
        if(Z_C[minpos]>Z_C[i]){
            minpos=i;
        }
    }
    if(Z_C[minpos]<0)
    return minpos;
    else{
        return -1; //if no negative elements
    }
}
int pivotrow(vector<vector<float> >A,vector<float> XB, int m,int min){
    int pos=-1;
    for(int i=0; i<m;++i){
        if(A[i][min]>0 && XB[i]/A[i][min]>=0){
            pos=i;
            break;   
        }
    }
    if(pos==-1){
        cout<<"\n problem is unbounded \n"; 
        return -1; // unbounded
    }
    for(int i=0;i<m;++i){
        if(A[i][min]>0 && XB[i]/A[i][min]>=0){
        if(XB[pos]/A[pos][min]>XB[i]/A[i][min]){
            pos=i;
        }}

    }
   
    return pos;
   
}

void itrtable(vector<vector<float> >&A, int m,int N ,int x , int y,vector<string>& V,vector<string>&bv ,vector<float>C,vector <float>&CB,vector<float>&Z_C,int eq,int su,int sl){
    bv[x]= V[y];
    CB[x]=C[y];
    float pvt=A[x][y];
     vector<vector<float> >temp(m, vector<float>(N+1));
     vector<float> ztemp(N+1);

    for(int i=0;i<m;++i){
        for(int j=0;j<=N;++j){ 
            if(i==x && j==y){
                temp[i][j]=1;
            }
           else if(i==x && j!=y){
            temp[i][j]=A[i][j]/pvt;
            }
            else if(i!=x && j==y){
                temp[i][j]=0;
            }
            else{
                temp[i][j]=A[i][j]-(A[i][y]*A[x][j]/pvt);

            }

        }
    }
     for(int i=0;i<=N;++i){
            ztemp[i]=Z_C[i]-(Z_C[y]*A[x][i]/pvt);
           
    }
     for(int i=0; i<m;++i){
        for(int j=0;j<=N;++j){
            A[i][j]=temp[i][j];
            
    }
    }
    for(int i=0;i<=N;++i){
           Z_C[i]= ztemp[i];

    }


}
int checkopt(vector<float>Z_C, int su,int N){
     for(int i=0;i<N;++i){
        if( Z_C[i]<0){
            return 0;
           }
    }
     return 1;
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
            }  
         }
    }
}
int main(){
    cout<<fixed<<setprecision(2);
    int m,n,minpos,pvtrow,N,zflag;                                        // no. of eqns and variables
    cout<<"Enter no. of eqns to be given ";
    cin>>m;
   cout<<"Enter no. of unknown variables excluding slack variables ";
    cin>>n;
    N=n+m;
    vector<vector<float> >A(m, vector<float>(N+1));
    vector<vector<float> >B(m, vector<float>(m));
    vector<vector<float> >Bi(m, vector<float>(m));
    vector<float> XM(m);
    vector<float> C(N+1);
    vector<float> Y(m);
    vector<float> Z_C(N+1);
    vector<string> V(N+1);
    vector<string> bv(m);
    vector<float> CB(m);
    
    //vector<float>B(m+1);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i==j){
            B[i][j]=1;
            Bi[i][j]=1;}
            else{
            B[i][j]=0;
            Bi[i][j]=0;}
        }
    }
    cout<<"Enter 1 if optimum func is maximize type else -1 \n";
    cin>>zflag;
    cout<<"Enter the  function Z = \n";
     for(int j=0;j<=N;j++){
        if(j<n){
            int temp;
            cin>>temp;
            C[j]=zflag*temp;                       
            } 
        else {
            C[j]=0;
        }    
    }  
    int k=0;
    cout<<"Enter Augmented matrix A|B:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<=N;j++){
                if(j<n || j==N){
                    
                    cin>>A[i][j]; 
                }
                else if(j==n+i ){
                    
                    A[i][j]=1;
                    string s="x";
                    s.append(to_string(j+1));
                    CB[k]=C[j];
                    bv[k]=s;
                    ++k;
                    
                }
                else {
                    A[i][j]=0;
                }
        }                                        
    }
    
    for(int i=0;i<N;++i){
            string s="x";
            s.append(to_string(i+1));
            V[i]=s;
        }
        V[N]="b";
    for(int i=0;i<=N;++i){
        Z_C[i]=-C[i];
        float x;
        for(int j=0;j<m;++j){
            Z_C[i]+=(CB[j]*A[j][i]);
        }
    }
    cout<<" \n\n Table T"<<i;
    cout<<endl;
    prntinttab(C,A, V,  m, n, bv, CB, Z_C,N,su);

//      int i=-1;
//    while(checkopt(Z_C,su,N)!=1 ){
//         ++i;
         
        cout<<"\nList of all basic variables are as follows ";
        for(int i=0;i<m;++i){
            cout<<bv[i]<<", ";
            }
        for(int i=0 ;i<m;++i){
            Y[i]=0;
            for(int j=0;j<m;++j){
                Y[i]+=CB[j]*Bi[j][i];
            }
        }    
        cout<<"\nList of all non basic variables are as follows ";
        for(int i=0;i<N;++i){
             int flag=0;
             for(int j=0;j<m;++j){
                if(bv[j]==V[i]){
                    flag=1;
                    break;
                }
            }
            if(flag!=1){
                cout<<V[i]<<", ";
                Z_C[i]=-C[i];
                for(int j=0 ;i<m;++i){
                    Z_C[i]+=Y[j]*A[j][i];
                }

                }
        }
        
        minpos=minPos(Z_C,N);
        for(int i=0;i<m;++i){
            XM[i]=0
            for(int j=0;j<m;++j){
                XM[i]+=Bi[i][j]*A[j][N];
            }
        }
        pvtrow=pivotrow(XM,m,minpos);
         if(pvtrow==-1){
            return 0;
        }
        for(int i=0;i<m;++i){
            B[i][pivotrow]=A[i][minpos];
        }
        vector<float> e(m);
        vector<float> u(m);
        for(int i=0;i<m;++i){
            e[i]=0;
            for(int j=0;j<m;++j){
                e[i]+=Bi[i][j]*A[j][pivotrow];
            }
        }
        for(int i=0;i<m;++i){
            u[i]=-e[i]/e[pivotrow];
            if(i==pivotrow){
                u[i]=1/e[pivotrow];
            }
        }
        vector<vector<float> >E(m, vector<float>(m));
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                E[i][j]=0;
                if(i==j){E[i][j]=1;}
                if(j==pivotrow){
                    E[i][j]=u[i];
                }
            }
        }
        vector<vector<float> >Bni(m, vector<float>(m));
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                Bni[i][j]=0;
                for(int k=0;k<m;++k){
                    Bni[i][j]+=E[i][k]*Bi[k][j];
                }
                
            }
        }
        
        //cout<<"\n pivot pos"<<pvtrow<<"  "<<minpos;
        // cout<<"\n minimum ratio is as follows "<<A[pvtrow][N]/A[pvtrow][minpos];
        itrtable(A,m,N,pvtrow,minpos,V,bv,C,CB,Z_C,eq,su,sl);
        

// }
  
    cout<<"\n\nnumber of iterations = "<<i+1;
    cout<<"\n";
  
    cout<<"\noptimal solution is as follows ";
    for(int i=0;i<n;++i){
        int flag=0;
        string s="x";
        s.append(to_string(i+1));
        cout<<s<<"= ";
        for(int j=0;j<eq+su+sl;++j){
            if(bv[j]==s){
                cout<<A[j][N]<<", ";
                flag=1;
                break;
            }   
    }
    if(flag==0){
        cout<<"0, ";
    }
    }
    cout<<"\n optimal value Z ="<<zflag*Z_C[N];
    cout<<endl;
    int altflag=0;
    prntinttab(C,A, V,  m, n, bv, CB, Z_C,N,su);
    for(int i=0;i<N;++i){                    // alternate solution check
             int flag=0;
             for(int j=0;j<eq+su+sl;++j){
                if(bv[j]==V[i]){
                    flag=1;
                    break;
                }
            }
            if(flag!=1 && Z_C[i]==0){
                altflag=1;
                break;
                }
        }
    if(altflag==0){
        cout<<"\n alternate solution doesn't exist";
    }
    else{
        cout<<"\n alternate solution exist";
    }
    int infeasible=0;
    for(int i=0;i<m;++i){                // infeasbile check
            for(int j=N;j>n+su+sl;--j){
                string s="x";
                 s.append(to_string(j));
                 if(s==bv[i]){
                    infeasible=1;
                    break;
                 }
            }
            if(infeasible==1){
                break;
            }
            }
    if(infeasible==1){
        cout<<"\n infeasible problem";
    }        
    return 0;
}

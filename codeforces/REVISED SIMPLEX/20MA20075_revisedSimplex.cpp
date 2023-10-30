#include<bits/stdc++.h>
#include<string.h>
using namespace std;

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
int pivotrow(vector<vector<float> >A,vector<float> X_B, int m,int N ,int min){
    int pos=-1;
    for(int i=0; i<m;++i){
        if(A[i][min]>0 && X_B[i]/A[i][min]>=0){
            pos=i;
            break;   
        }
    }
    if(pos==-1){
        cout<<"\n problem is unbounded \n"; 
        return -1; // unbounded
    }
    for(int i=0;i<m;++i){
        if(A[i][min]>0 && X_B[i]/A[i][min]>=0){
        if(X_B[pos]/A[pos][min]>X_B[i]/A[i][min]){
            pos=i;
        }}

    }
    return pos;
}

void itrtable(vector<vector<float> >&A, int m,int N ,int x , int y,vector<string>& V,vector<string>&bv ,vector<float>C,vector <float>&CB,vector<float>&Z_C){
    bv[x]= V[y];
    CB[x]=C[y];
}
int checkopt(vector<float>Z_C,int N){
     for(int i=0;i<N;++i){
        if( Z_C[i]<0){
            return 0;
           }
    }
     return 1;
}
int main(){
    cout<<fixed<<setprecision(2);
    int m,n,minpos,pvtrow,N,zflag;                                        // no. of eqns and variables
    cout<<"Enter no. of eqns to be given ";
    cin>>m;
   cout<<"Enter no. of unknown variables excluding  slack  variables ";
    cin>>n;
    N=n+m;
    vector<vector<float> >A(m, vector<float>(N+1));
    vector<vector<float> >B(m, vector<float>(m));
    vector<vector<float> >Bin(m, vector<float>(m));
    vector<float> X_B(m);
    vector<float> C(N+1);
    vector<float> Z_C(N+1);
    vector<string> V(N+1);
    vector<string> bv(m);
    vector<float> CB(m);
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            B[i][j]=0;
            Bin[i][j]=0;
            if(i==j){
                B[i][j]=1;
                Bin[i][j]=1;
            }
        }
    }
    
    cout<<"Enter 1 if optimum func is maximize type else -1 \n";
    cin>>zflag;
    cout<<"Enter the  function Z = \n";
     for(int j=0;j<N;j++){
        if(j<n){
            int temp;
            cin>>temp;
            C[j]=zflag*temp;                       
            }  
        else {
            C[j]=0;
        }    
        }  
        C[N]=0;                          
    // cout<<"enter constant term in maximize func \n";
    // cin>>C[N];
    int k=0;
    cout<<"Enter Augmented matrix A|B:  \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<=N;j++){
                if(j<n || j==N){
                    
                    cin>>A[i][j]; 
                }
                else if(j==n+i ){
                    
                    A[i][j]=1; vector<vector<float> >Bin(m, vector<float>(m));
                    A[i][j]=0;
                }                        // entering coeffeicient matrix
        } 
                                              
    }
    
    for(int i=0;i<N;++i){
            string s="x";
            s.append(to_string(i+1));
            V[i]=s;
        }
        V[N]="b";
      
    for(int i=0;i<m;++i){
        CB[i]=0;
    }

    for(int i=0;i<=N;++i){
        Z_C[i]=-C[i];
        float x;
        for(int j=0;j<m;++j){
            Z_C[i]+=(CB[j]*A[j][i]);
        }
    }
 

     int i=-1;
  while(checkopt(Z_C,N)!=1 ){
        ++i;
          cout<<" \n\n iteration"<<i;
          cout<<"\n basis matrix is as follows\n";
          for(int i=0;i<m;++i ){
            for(int j=0;j<m;++j){
                cout<<B[i][j]<<" ";
            }
            cout<<endl;
          }
          cout<<"\n C_B matrix is as follows\n";
          for(int i=0;i<m;++i ){
            cout<<CB[i]<<" ";
          }


          vector<float> y(m);
          
          vector<float> e(m);
          vector<float> p(m);
        vector<vector<float> >E(m, vector<float>(m));
        vector<vector<float> >Bnin(m, vector<float>(m));
          

           
        minpos=minPos(Z_C,N);
            for(int i=0;i<m;++i ){
                X_B[i]=0;
            for(int j=0;j<m;++j){
                X_B[i]+=Bin[i][j]*A[j][N];
            }
          }
          cout<<"\n X_B is as follows\n";
          for(int i=0; i<m;++i){
            cout<<X_B[i]<<" ";
          }

        pvtrow=pivotrow(A,X_B,m,N,minpos);
         if(pvtrow==-1){
            return 0;
        }
        
        for(int i=0;i<m;++i){
            B[i][pvtrow]=A[i][minpos];
        }
        // cout<<"\n new matrix B\n"; //**************
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<m;++j){
        //         cout<<B[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<m;++i){
            e[i]=0;
            for(int j=0;j<m;++j){
                e[i]+=Bin[i][j]*A[j][minpos];
            }
        }
        // cout<<" \n matrix e \n"; //***************
        // for(int i=0;i<m;++i){
        //     cout<<e[i]<<" ";
        // }
        for(int j=0;j<m;++j){
            p[j]=-e[j]/e[pvtrow];
            if(j==pvtrow){p[j]=1/e[pvtrow];}
        }
        // cout<<" \n matrix p \n"; //***************
        // for(int i=0;i<m;++i){
        //     cout<<p[i]<<" ";}

        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                E[i][j]=0;
                if(i==j){
                    E[i][j]=1;
                }
                if(j==pvtrow){
                    E[i][j]=p[i];
                }
            }

        }
        // cout<<"\n new matrix E\n"; //**************
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<m;++j){
        //         cout<<E[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                Bnin[i][j]=0;

                for(int l=0;l<m;++l){
                    Bnin[i][j]+=E[i][l]*Bin[l][j];
                }
            }

        }
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
               Bin[i][j]=Bnin[i][j];
                
            }

        }
        //  cout<<"\n new matrix Binverse\n"; //**************
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<m;++j){
        //         cout<<Bin[i][j]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        

        //cout<<"\n pivot pos"<<pvtrow<<"  "<<minpos;
        // cout<<"\n minimum ratio is as follows "<<A[pvtrow][N]/A[pvtrow][minpos];
        itrtable(A,m,N,pvtrow,minpos,V,bv,C,CB,Z_C);
         for(int i=0;i<m;++i ){
                y[i]=0;
            for(int j=0;j<m;++j){
                y[i]+=CB[j]*Bin[j][i];
            }
          }
          for(int i=0;i<m;++i ){
                Z_C[i]=-C[i];
            for(int j=0;j<m;++j){
                Z_C[i]+= y[j]*A[j][i];
            }
          }
 }
  
    // cout<<"\n\nnumber of iterations = "<<i+1;
    // cout<<"\n";
  
     cout<<"\noptimal solution is as follows ";
     for(int i=0;i<m;++i){
        X_B[i]=0;
        for(int j=0;j<m;++j){
            X_B[i]+=Bin[i][j]*A[j][N];
        }
     }
    for(int i=0;i<n;++i){
        int flag=0;
        string s="x";
        s.append(to_string(i+1));
        cout<<s<<"= ";
        for(int j=0;j<m;++j){
            if(bv[j]==s){
                cout<<X_B[j]<<", ";
                flag=1;
                break;
            }   
    }
    if(flag==0){
        cout<<"0, ";
    }
    } 
     cout<<"\n optimal value is as follows ";
     int z=0;
     for(int i=0;i<m;++i){
        z+=CB[i]*X_B[i];
     }
     cout<<z;     
    return 0;
}

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void prntinttab(vector<vector<float> >&A, int m,int n,vector<string> nbv,vector<string>bv,int f ){
    for(int i=0;i<n-m+2*f;++i){
        cout<<"-"<<nbv[i]<<" ";
    }
    cout<<nbv[n-m+2*f]<<"\n";
    for(int i=0;i<m+1;++i){
        for(int j=0;j<=n+2*f;++j){
            cout<<A[i][j]<<"  ";
            if(j==n-m+2*f-1){
                j=n+2*f-1;
            }
        }
        cout<<" ="<<bv[i]<<"\n";
    }
}
int minPos(vector<vector<float> >&A, int m,int n,int f ){
    int minpos=0;
    for(int i=1;i<n-m+2*f;++i){
        if(A[m][minpos]>A[m][i]){
            minpos=i;
        }
        
    }
    
    if(A[m][minpos]<0)
    return minpos;
    else{
        return -1; //if no negative elements
    }
}
int pivotrow(vector<vector<float> >&A, int m,int n ,int min, int f){
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
        if(A[i][min]>0 && A[i][n+2*f]/A[i][min]>=0){
        if(A[pos][n+2*f]/A[pos][min]>A[i][n+2*f]/A[i][min]){
            pos=i;
        }}

    }
   
    return pos;
   
}
void itrtable(vector<vector<float> >&A, int m,int n ,int x , int y,vector<string>& nbv,vector<string>&bv ,int f){
    string s= nbv[y];
    nbv[y]=bv[x];
    bv[x]=s;
    float pvt=A[x][y];
     vector<vector<float> >C(m+1, vector<float>(n+1+2*f));
    for(int i=0; i<=m;++i){
        for(int j=0;j<=n+2*f;++j){ 
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
        for(int j=0;j<=n+2*f;++j){
            A[i][j]=C[i][j];
            
    }
    }

}
int checkopt(vector<vector<float> >&A, int m,int n, int f ){
   
    for(int j=0;j<n+2*f;j++){
            
           if( A[m][j]<0){
            return 0;
           }
        }
        return 1;
}
void prntbfs(vector<vector<float> > A, int m,int n ,vector<string> nbv,vector<string> bv,int f){
    
    for(int i=0;i<n-m+2*f;++i){
        string s="x";
        s.append(to_string(i+1));
        int flag=0;
        cout<<s<<" = ";
        for(int j=0;j<n-m+2*f;++j){
            
            if(nbv[j]==s){
                cout<<"0 ,";
                flag=1;
                break;
            }
            
        }
        for(int j=0;j<m && flag!=1;++j){
        if(bv[j]==s){
         cout<<A[j][n+2*f]<<" ";
         break;
    }}
}}
int main(){
    int m,n,minpos,pvtrow,f;                                        // no. of eqns and variables
    cout<<"Enter no. of eqns to be given ";
    cin>>m;
   cout<<"Enter no. of unknown variables including slack variables excluding free variables ";
    cin>>n;
    cout<<"Enter no. of free variables ";
    cin>>f;
    vector<vector<float> >A(m+1, vector<float>(n+1+2*f));
    vector<string> nbv(n-m+2*f+1);
    vector<string> bv(m+1);
    
 

    cout<<"Enter Augmented matrix A|B: (first coefficient of normal variables then free variables and then slack variables\n";
     cout<<"x1 +0x2+ y1 +0y2 + s1+ 0s2 =16 to be  written as 1 0 1 0 1 0 16 y is free variables; si are slack variables \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<=n+2*f;j++){   // entering coeffeicient matrix
            if(j<=n-1-m || j>= n-m+2*f){
                cin>>A[i][j];   
            }
            else{  
                int x;
                cin>>x;  
                A[i][j]=x;
                A[i][++j]=-x;                
            }
                                    
        }
                                        
    }
    cout<<"Enter the maximize function Z = (first coeff of normal variables then free variables then slack)\n";
    cout<<"Z=x1 +3x2+ y1 +2y2 + 0s1+ 0s2 =16 to be  written as 1 3 1 2 0 0 y is free variables; si are slack variables \n";
     for(int j=0;j<n+2*f;j++){                    // entering maximize function
            int temp;
            cin>>temp;
            
            if(j<=n-1-m || j>= n-m+2*f ){
                 A[m][j]=-temp;
            }
            else{
                A[m][j]=-temp;
                A[m][++j]=temp;                
            }
                                    
        }
                                     
    cout<<"enter constant term in maximize func \n";
    cin>>A[m][n+2*f];
    for(int i=0;i<n-m+2*f;++i){
       
            string s="x";
            s.append(to_string(i+1));
            nbv[i]=s;
        }
        nbv[n-m+2*f]="1";
      
    for(int i=0;i<m;++i){
        string s="s";
        s.append(to_string(i+1));
        bv[i]=s;
    }
    bv[m]="Z";
    int i=-1;
 
    while(checkopt(A,m,n,f)!=1){
        ++i;
        cout<<" \n\n Simplex Table T"<<i;
        cout<<"\n";
        cout<<"\n basic feasible solution  ";
        prntbfs(A,m,n,nbv,bv,f);
         cout<<"\n objective value Z ="<<A[m][n+2*f]<<" ";
         minpos=minPos(A,m,n,f);
        pvtrow=pivotrow(A,m,n,minpos,f);
         if(pvtrow==-1){
                return 0;
            }
        printf("\n pivot element is  present at (%d,%d) ",pvtrow,minpos);
        cout<<" \n pivote element = "<<A[pvtrow][minpos];
        itrtable(A,m,n,pvtrow,minpos,nbv,bv,f);
        prntinttab(A,m,n,nbv,bv,f);
   }
    cout<<"\n\nnumber of iterations = "<<i+1;
    cout<<"\n";
  prntinttab(A,m,n,nbv,bv,f);
    cout<<"\n optimal solution is as follows ";
     for(int i=0;i<n-m;++i){
        string s="x";
        s.append(to_string(i+1));
        int flag=0;
        cout<<s<<" = ";
            for(int j=0;j<n-m+2*f;++j){
                
                if(nbv[j]==s){
                    cout<<"0 ,";
                    flag=1;
                    break;
                }
                
            }
            for(int j=0;j<m && flag!=1;++j){
                if(bv[j]==s){
                cout<<A[j][n+2*f]<<" ";
                break;}    
            }
    }
    float x1,x2;
    int k=0,l=0;
    for(int i=n-m;i<n-m+2*f;++i){
        string s="x";
        s.append(to_string(i+1));
        int flag=0;
        
       // cout<<s<<" = ";
            for(int j=0;j<n-m+2*f;++j){
                
                if(nbv[j]==s){
                    x1=0;
                    //cout<<"0 ,";
                    flag=1;
                    break;
                }
                
            }
            for(int j=0;j<m && flag!=1;++j){
                if(bv[j]==s){
                x1=A[j][n+2*f];
                 //cout<<A[j][n+2*f]<<" ";
                break;}    
            }
            ++k;
            //cout<<x1;
            if(k==1){
                x2=x1;
            }
            if(k==2){
                ++l;
                cout<<", y"<<l<<"= "<<x2-x1;
                k=0;
            }
    }
    cout<<"\n optimal value Z ="<<A[m][n+2*f];
    return 0;
}

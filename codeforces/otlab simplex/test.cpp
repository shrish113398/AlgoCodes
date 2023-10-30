#include<bits/stdc++.h>
using namespace std;
int main(){ vector<string> nbv(2);
for(int i=0;i<=1;++i){
        string s="x";
        s.append(to_string(i));
        nbv[i]=s;
    }
    for(int i=0;i<=1;++i){
        cout<<nbv[i];
    }

    return 0;}
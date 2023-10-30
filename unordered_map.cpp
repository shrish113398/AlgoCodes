#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> s;
    s["gfg"]=20;
    s["abc"]=10;
    s["ziz"]=0;
    if (s.find("ziz")!=s.end()) 
    {
        cout<<"found"<<endl;
    }
    else{
        cout<<"Not -  found"<<endl;
    }
}
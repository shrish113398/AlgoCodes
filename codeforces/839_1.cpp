#include<iostream>
using namespace std;
int main()
{
    
    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;
        int a=int (str.at(0));
        int b=int (str.at(2));
        int sum = a+b-(2*48);
        cout<<sum<<"\n";
    }
}
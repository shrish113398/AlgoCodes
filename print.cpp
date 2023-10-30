#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "please enter your age: ";
    cin >> age;
    if (age < 18 && age > 0)
    {
        cout << "get the hell out of here";
    }
    else if (age >= 18 && age <= 1000)
    {
        cout << "hop into the party";
    }
    else
    {
        cout << "u r fricking immortal dude ";
    }
    return 0;
}


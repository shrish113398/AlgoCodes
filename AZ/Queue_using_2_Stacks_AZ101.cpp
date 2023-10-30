#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        stack<int> s1, s2;
        int front = 0;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if(s == "push") {
                int x;
                cin >> x;
                if(s1.empty()) {
                    front = x;
                }
                s1.push(x);
            }
            else if(s == "pop") {
                if(s2.empty()) {
                    while(!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                int x = s2.top();
                s2.pop();
                cout << x << "\n";
            }
            else { // front
                if(s2.empty()) {
                    cout << front << "\n";
                }
                else {
                    cout << s2.top() << "\n";
                }
            }
        }
    }
    return 0;
}
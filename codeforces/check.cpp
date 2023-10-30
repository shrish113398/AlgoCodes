#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2005;

int n;
char s[MAXN];

bool check() {
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        bool can_convert = false;
        for (char c = 'a'; c <= 'z'; c++) {
            bool all_same = true, all_diff = true;
            for (int i = 0; i < n; i++) {
                if (s[i] != c) {
                    all_same &= (s[i] == s[0]);
                    all_diff &= (s[i] != s[0]);
                }
            }
            if (all_same || all_diff) {
                can_convert = true;
                break;
            }
        }
        if (can_convert && check()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

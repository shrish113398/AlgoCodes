#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int n;
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(i);
  }
  do {
    for (int i = 0; i < n; ++i) {
      cout << v[i] << " ";
    }
    cout << "\n";
  } while (next_permutation(v.begin(), v.end()));
  return 0;
}
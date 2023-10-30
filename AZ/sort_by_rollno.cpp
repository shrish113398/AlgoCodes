#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

bool comp(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<string, int>> v;
    for (int i = 0; i < n; ++i) {
      string s;
      int r;
      cin >> s >> r;
      v.push_back({s, r});
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; ++i) {
      cout << v[i].first << " " << v[i].second << "\n";
    }
  }
  return 0;
}
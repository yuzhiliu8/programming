#include <bits/stdc++.h>

using namespace std;

void solve() {

  int n;
  cin >> n;

  unordered_map<int, int> map;

  int max = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    map[a]++;
    if (map[a] > max) {
      max = map[a];
    }
  }

  // for (auto& pair : map) {
  //   cout << pair.first << ' ' << pair.second << '\n';
  // }
  // cout << max << '\n';
  for (int i = 0; i < max; ++i) {
    vector<int> vec;
    for (auto &pair : map) {
      if (pair.second > 0) {
        auto it = lower_bound(vec.begin(), vec.end(), pair.first);
        vec.insert(it, pair.first);
        --pair.second;
      }
    }

    for (int i = vec.size() - 1; i > -1; --i) {
      cout << vec[i] << ' ';
    }
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;

  string s;
  cin >> s;

  int l = 0;
  int r = n - 1;

  int count = 0;
  while (l < r) {
    char left = s[l];
    char right = s[r];

    if (left == right) {
      ++l;
      --r;
      continue;
    } else {
      if (left != c) {
        count++;
      }
      if (right != c) {
        count++;
      }
    }
    ++l;
    --r;
  }

  cout << count << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

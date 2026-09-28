#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    int sum = 0;
    for (auto kv : freq){
        sum += kv.second / 2;
    }

    cout << sum << '\n';

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}
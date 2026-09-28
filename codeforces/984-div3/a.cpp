#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++){
        int diff = abs(arr[i] - arr[i+1]);
        if (diff != 5 && diff != 7){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int t;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}
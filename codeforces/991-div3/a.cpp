#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        arr[i] = s.length();
    }

    int sum = 0;
    int index = 0;

    while (sum < m && index < n){
        sum += arr[index];
        index++;
    }

    if (sum > m){
        cout << index-1 << endl;
    }
    else {
        cout << index << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}


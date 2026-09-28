#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

void solve(){
    int k;
    cin >> k;
    int arr[k];
    unordered_map<int, int> freq;

    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        arr[i] = x;
        // cout << arr[i] << ' ';
        freq[x]++;
    }

    int total = k-2;
    // cout << total << endl;
    for (int i = 0; i < k; i++){
        if (total%arr[i] == 0){
            int target = total/arr[i];
            if (target == arr[i] && freq[target] > 1){
                cout << arr[i] << ' ' << target << endl;
                return;
            }
            else if (target != arr[i] && freq[target] > 0){
                cout << arr[i] << ' ' << target << endl;
                return;
            }
        }
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
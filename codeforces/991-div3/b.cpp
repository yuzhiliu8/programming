#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    
    int evens = 0;
    int odds = 0;
    ll even_sum = 0;
    ll odd_sum = 0;
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            evens++;
            even_sum += arr[i];
        }
        else{
            odds++;
            odd_sum += arr[i];
        }
    }

    float odd_div = float(odd_sum) / odds;
    float even_div = float(even_sum) / evens;

    if (odd_div == even_div && (odd_sum % odds == 0) && (even_sum % evens == 0)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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
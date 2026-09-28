#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

void solve(){
    string n;
    cin >> n;
    int cnt_two = 0;
    int cnt_three = 0;
    int digit_sum = 0; 
    for (int i = 0; i < n.length(); i++){
        if (n[i] == '2'){
            cnt_two++;
        }
        else if (n[i] == '3'){
            cnt_three++;
        }
        digit_sum += (int n[i]);
    }

    if (digit_sum % 9 == 0){
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < cnt_two; i++){
       digit_sum += 6;
       if (digit_sum % 9 == 0){
        cout << "YES" << endl;
        return;
       } 
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}  
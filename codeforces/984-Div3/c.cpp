#include <bits/stdc++.h>

using namespace std;

int check_string(string s){
    int cnt = 0;
    for (int i = 0; i < s.length()-3; i++){
            if (s.substr(i, 4) == "1100"){
                cnt++;
            }
    }
    return cnt;
}


void solve(){
    string s;
    cin >> s;

    int q;
    cin >> q;

    int cnt = check_string(s);

    for (int i = 0; i < q; i++){
        int pos, v;
        cin >> pos >> v;


        string sub = s.substr(max(0, pos-4), min(8, max(0, pos-3) + 6));
        int before = check_string(sub);
        s[pos-1] = '0' + v;
        sub = s.substr(max(0, pos-4), min(8, max(0, pos-3) + 6));
        int after = check_string(sub);

        cnt = cnt + (after - before);
        
        if (cnt > 0){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
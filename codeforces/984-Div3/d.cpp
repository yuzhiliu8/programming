#include <bits/stdc++.h>

using namespace std;

int count_layer(string s){
    int cnt = 0;
    for (int i = 0; i < s.length()-3; i++){
        if (s.substr(i, 4) == "1543"){
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    int n, m;
    cin >> n >> m;

    string wall[n][m];

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        for (int j = 0; j < m; j++){
            wall[i][j] = s[j];
        }
    }

    int start = 0;
    int x, y;
    int cnt = 0;
    while (start < m/2 && start < n/2){
        x = start;
        y = start;
        string layer_str = "";
        while (y < m - start){ //Traverse left to right
            // cout << x << ' ' << y << endl;
            layer_str += wall[x][y];
            y++;
        }
        y--;
        x++; //prevent duplicates
        while (x < n - start){ // top to bottom
            layer_str += wall[x][y];
            x++;
        }
        x--;
        y--; //prevent duplicates
        while (y > start-1){ // right to left
            layer_str += wall[x][y];
            y--;
        }
        y++;
        x--; // prevent duplicates
        while (x > start){
            layer_str += wall[x][y];
            x--;
        }

        layer_str += layer_str.substr(0, 3);
        cnt += count_layer(layer_str);
        start++;
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}

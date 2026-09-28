#include <bits/stdc++.h>

using namespace std;

// COL = region number
// ROW = country number
int search(int* values, int rows, int cols, int region, string op, int limit){
    for (int i = 0; i < rows; i++){
        cout << *((values + i * cols) + region) << ' ';
        cout << endl;
    }
    cout << endl;

    int low = 0;
    int high = rows;
    int index = -1;
    if (op == "greater"){
        //Find index of smallest value bigger than LIMIT
        while (low < high){
            int mid = (low + high)/2;
            int mid_val = *((values + mid * cols) + region);
            int prev_mid_val = *((values + (mid-1) * cols) + region);
            if (prev_mid_val =< limit && mid_val > limit){
                index = mid;
                break;
            }
            else if (prev_mid_val > limit){

            }
        }
    }
    

    return 3;
}

int main(){
    int n, k, q;
    cin >> n >> k >> q;

    int values[n][k];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cin >> values[i][j];
            if (i > 0){
                values[i][j] = values[i-1][j] | values[i][j];
            }
            cout << values[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    int region = 1;
    search((int*)values, n, k, region-1, "greater", 4);

    for (int i = 0; i < q; i++){
        int m;
        cin >> m;
        for (int j = 0; j < m; j++){
            int region, operation, limit;
            cin >> region >> operation >> limit;

        }
    }





    return 0;
}
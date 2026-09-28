#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int curr;

    int mx = 0;
    int mn = 1001;
    for (int i = 0; i < n; i++){
        cin >> curr;
        if (curr > mx) mx = curr;
        if (curr < mn) mn = curr;
    }

    int diff = mx - mn;
    cout << diff * (n-1) << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
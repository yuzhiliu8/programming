#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int costs[k] = {0};
    for (int i = 0; i < k; i++){
        int b, c;
        cin >> b >> c;
        costs[b-1] += c;
    }

    sort(costs, costs + k, greater<int>());
    int sum = 0;
    int mx = min(n, k);
    for (int i = 0; i < mx; i++){
        sum += costs[i];
    }

    cout << sum << '\n';


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
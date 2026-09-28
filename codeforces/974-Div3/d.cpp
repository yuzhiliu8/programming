#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> pref(n + 2);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        pref[max(1, a-d+1)]++;
        pref[b + 1]--;
    }

    for (int i = 0; i < n; i++){
        pref[i+1] = pref[i+1] + pref[i];
    }


    int mx = 0;
    int mn = 1e9;
    int rob = 1;
    int mom = 1;
    for (int i = 1; i < n+2-d; i++){
        if (pref[i] > mx) {
            mx = pref[i];
            rob = i;
        }

        if (pref[i] < mn){
            mn = pref[i];
            mom = i;
        }
    }
    cout << rob << ' ' << mom << endl;
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
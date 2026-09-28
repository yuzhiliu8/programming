#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    int gold = 0;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a >= k)
        {
            gold += a;
        }
        else if (a == 0 && gold > 0)
        {
            gold--;
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
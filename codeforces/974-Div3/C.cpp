#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> pop(n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pop[i];
        sum += pop[i];
    }

    if (n == 1 || n == 2)
    {
        cout << -1 << endl;
        return;
    }

    sort(pop.begin(), pop.end());

    float average = sum / n;
    long long mid = pop[(n / 2)];

    long long min_x = max(0LL, (2 * mid * n - sum) + 1);
    cout << min_x << endl;
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
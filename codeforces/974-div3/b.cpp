#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    int sum = 0;
    if (k == 1)
    {
        sum = n;
    }
    else
    {
        if (n > k)
        {
            int start = n - k + 1;
            int end = n;
            sum = (start + end) * (end - start + 1) / 2;
        }
        else
        {
            int start = 1;
            int end = n;
            sum = (start + end) * (end - start + 1) / 2;
        }
    }

    if (sum % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
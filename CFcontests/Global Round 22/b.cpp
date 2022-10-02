#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> s(k);
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }

    if (k == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    for (int i = 1; i < k - 1; i++)
    {
        if (s[i] - s[i - 1] > s[i + 1] - s[i])
        {
            cout << "No" << endl;
            return;
        }
    }

    long long mx = s[1] - s[0];
    if (mx * (n - k + 1) < s[0])
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
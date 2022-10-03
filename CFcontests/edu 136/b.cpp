#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (d[i - 1] - d[i] >= 0 && d[i] != 0)
        {
            // cout << i << endl;
            cout << -1 << endl;
            return ;
        } else {
            d[i] += d[i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
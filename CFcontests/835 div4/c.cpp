#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long mx1 = 0, mx2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] > mx1)
        {
            mx2 = mx1;
            mx1 = a[i];
        } else if (a[i] > mx2)
        {
            mx2 = a[i];
        }
    }

    // cout << mx1 << ' ' << mx2 << endl;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx1)
        {
            cout << (a[i] - mx2) << ' ';
        } else {
            cout << (a[i] - mx1) << ' ';
        }
    }
    cout << endl;
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
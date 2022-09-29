#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= 2;
    }

    cout << n - 1 << endl;
    if (n == 1)
    {
        return;
    }
    if ((a[0] + a[n - 1]) % 2 == 0)
    {
        a[0] = a[n - 1];
    } else {
        a[n - 1] = a[0];
    }
    cout << 1 << ' ' << n << endl;
    for (int i = 1; i < n - 1; i++)
    {
        if ((a[0] + a[i]) % 2 == 0)
        {
            cout << i + 1 << ' ' << n << endl;
        } else {
            cout << 1 << ' ' << i + 1 << endl;
        }
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
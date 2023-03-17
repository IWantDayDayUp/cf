#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt += a > 0;
    }

    int p = n - cnt;
    // cout << p << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << (i <= cnt ? i : --cnt) << " \n"[i == n];
    }

    for (int i = 0; i < p; i++)
    {
        cout << 1 << ' ' << 0 << ' ';
    }

    if (n - 2 * p == 0)
    {
        cout << endl;
    }

    for (int i = 1; i <= n - 2 * p; i++)
    {
        cout << i << " \n"[i == n - 2 * p];
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
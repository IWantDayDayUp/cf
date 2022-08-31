#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<long long> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        if (s[i] == 'L')
        {
            cur = i;
        } else {
            cur = n - i - 1;
        }

        ans += cur;

        a[i] = max(i, n - i - 1) - cur;
    }
    sort(a.rbegin(), a.rend());

    vector<long long> pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans + pre[i] << " \n"[i == n];
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
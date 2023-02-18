#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        pre[i + 1] = pre[i] + b[i];
    }

    vector<long long> add(n + 1), cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int cur = upper_bound(pre.begin(), pre.end(), a[i] + pre[i]) - pre.begin() - 1;

        cnt[i] += 1;
        cnt[cur] -= 1;

        add[cur] += a[i] - (pre[cur] - pre[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << (add[i] + cnt[i] * b[i]) << " \n"[i == n - 1];
        
        cnt[i + 1] += cnt[i];
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
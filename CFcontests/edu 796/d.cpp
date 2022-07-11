#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    if (k >= n)
    {
        cout << pre[n] + (k - 1ll + k - n) * n / 2 << endl;
    } else {
        i64 mx = pre[k];
        for (int i = k + 1; i <= n; i++)
        {
            mx = max(mx, pre[i] - pre[i - k]);
        }

        cout << mx + k * (k - 1ll) / 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 3)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n + 3);
    iota(ans.begin(), ans.end(), 1);

    if (n & 1)
    {
        for (int i = 1; i < n; i+=2)
        {
            swap(ans[i], ans[i + 1]);
        }
        ans[n] = 1;
        ans[n + 1] = 2;
        ans[n + 2] = 3;
        for (int i = 3; i < n + 3; i++)
        {
            cout << ans[i] << " \n"[i == n + 2];
        }
    } else {
        for (int i = 0; i < n; i+=2)
        {
            swap(ans[i], ans[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
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
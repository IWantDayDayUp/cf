#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        cnt[p] += 1;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }

        ans += min(cnt[i], c);
    }

    cout << ans << endl;
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
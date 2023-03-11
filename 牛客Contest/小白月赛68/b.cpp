#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        int k, x, y;
        cin >> k >> x >> y;

        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;

            int t = v;
            if (v >= a)
            {
                t -= b;
            }
            if (v >= x)
            {
                t -= y;
            }

            ans = min(ans, max(0, t));
        }
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
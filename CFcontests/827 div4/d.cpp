#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(1000 + 5, -1);
    for (int i = 1; i <= n; i++)
    {
        int cur;
        cin >> cur;

        a[cur] = i;
    }

    int ans = -1;
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] == -1) continue;
        for (int j = i; j <= 1000; j++)
        {
            if (a[j] == -1) continue;

            if (__gcd(i, j) == 1)
            {
                ans = max(ans, a[i] + a[j]);
            }
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
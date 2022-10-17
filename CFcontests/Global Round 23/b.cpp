#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    int l = 0, r = n - 1;
    while (l < r)
    {
        while (l < r && a[l] == 0)
        {
            l += 1;
        }
        while (r > l && a[r] == 1)
        {
            r -= 1;
        }

        if (l != r)
        {
            ans += 1;
        }

        l += 1;
        r -= 1;
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
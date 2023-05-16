#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if (c == 0)
        {
            cnt += 1;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
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
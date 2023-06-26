#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long ans = 0;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        ans += abs(a);

        if (a < 0 && !flag)
        {
            flag = true;
            cnt += 1;
        } else if (a > 0)
        {
            flag = false;
        }
    }

    cout << ans << ' ' << cnt << endl;
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
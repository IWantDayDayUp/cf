#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int cur = 0, cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        auto calc = [](int p)
        {
            if (p == 0)
            {
                return 0;
            } else if (p & 1)
            {
                return (p + 1) / 2;
            } else {
                return 1 + p / 2;
            }
        };

        if (a == 1)
        {
            cur += 1;
            ans = max(ans, calc(cnt) + cur);
        } else {
            cnt += cur;
            cur = 0;

            ans = max(ans, calc(cnt));
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
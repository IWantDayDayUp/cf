#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;

        if (m >= cur)
        {
            m -= cur;
        } else {
            ans += cur - m;
            m = 0;
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
        slove();
    }

    return 0;
}
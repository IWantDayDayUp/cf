#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int l, r;
    cin >> l >> r;
    int cnt[32][2];
    memset(cnt, 0, sizeof cnt);
    for (int i = l; i <= r; i++)
    {
        int cur;
        cin >> cur;

        for (int p = 0; p <= 30; p++, cur >>= 1)
        {
            cnt[p][cur & 1] += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 30; i++)
    {
        ans |= ((cnt[i][0] < cnt[i][1]) * (1 << i));
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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    long long ans = 0, mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        int next = (i + 1) % n;
        // 
        long long demage = min(a[next], b[i]);
        // 额外需要的子弹
        ans += a[next] - demage;
        mn = min(mn, demage);
    }

    ans += mn;
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
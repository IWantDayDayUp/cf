#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    ans += (b > a) + (c > a) + (d > a);

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
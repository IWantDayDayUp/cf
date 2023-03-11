#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        swap(a, b);
    }

    long long l = 1, r = 1e9;
    while (l < r)
    {
        long long mid = l + r >> 1;
        long long cnt = mid * mid;

        long long x = cnt + 1 >> 1;
        long long y = cnt >> 1;

        if (a <= x && b <= y)
        {
            r = mid;
        } else {
            l = mid + 1;
        }

        // cout << mid << endl;
    }

    cout << l << endl;
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
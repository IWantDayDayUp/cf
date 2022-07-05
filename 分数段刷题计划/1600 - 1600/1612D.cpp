#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long a, b, x;
    cin >> a >> b >> x;

    function<bool(long long, long long, long long)> get = [&](long long a, long long b, long long x)
    {
        if (a == x || b == x) return true;
        if (a < b) swap(a, b);
        if (b > a - b) b = a - b;
        if (x > max(a, b) || a == 0 || b == 0) return false;
        long long cnt = max(1ll, (a - max(x, b)) / (2 * b));
        return get(a - b * cnt, b, x);
    };

    cout << (get(a, b, x) ? "YES" : "NO") << endl;
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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;

    if (m >= x)
    {
        cout << t << endl;
    } else {
        cout << t - x * d + m * d << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long a, b;
    cin >> a >> b;

    if (b == 1)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << a << ' ' << a * b << ' ' << a * (b + 1) << endl;
    }
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
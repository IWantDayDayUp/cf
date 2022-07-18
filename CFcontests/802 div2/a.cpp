#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long n, m;
    cin >> n >> m;

    long long s = m * (1 + m) / 2;
    s += n * (m + n * m) / 2;
    s -= m;

    cout << s << endl;
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
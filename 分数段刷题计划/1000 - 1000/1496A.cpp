#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    long long n, k;
    cin >> n >> k;

    long long s = n;
    int need = (k - (s % k)) % k;

    cout << (1 + need / n + 1 * (need % n > 0))<< endl;
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
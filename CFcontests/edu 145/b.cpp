#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long x = sqrt(n);
    while (x * x < n)
    {
        x += 1;
    }
    while ((x - 1) * (x - 1) >= n)
    {
        x -= 1;
    }

    x -= 1;

    cout << x << endl;
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
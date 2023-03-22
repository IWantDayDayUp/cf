#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a + b == c ? '+' : '-') << endl;
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
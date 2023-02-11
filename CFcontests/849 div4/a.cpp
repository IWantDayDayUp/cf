#include <bits/stdc++.h>

using namespace std;

void solve() {
    char c;
    cin >> c;

    string s = "codeforces";

    if (s.find(c) != -1)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
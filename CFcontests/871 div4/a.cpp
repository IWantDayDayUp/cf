#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t = "codeforces";
    cin >> s;

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += s[i] != t[i];
    }

    cout << ans << endl;
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
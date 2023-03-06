#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = n - 1;
    for (int i = 1; i <= n - 2; i++)
    {
        if (s[i - 1] == s[i + 1])
        {
            ans -= 1;
        }
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
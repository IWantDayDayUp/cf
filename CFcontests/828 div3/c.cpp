#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    vector<int> p(2 * n, 1e9);
    s += s;

    int ans = 0;

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (l <= i) l = i;
        if (s[i] != c) continue;
        while (l < 2 * n && s[l] != 'g')
        {
            l += 1;
        }

        ans = max(ans, l - i);
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
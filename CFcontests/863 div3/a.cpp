#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, c;
    string s;
    cin >> n >> c >> s;

    string ans = "";

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' < c)
        {
            ans += (char)('0' + c) + s.substr(i, n - i + 1);
            ok = true;
            break;
        }

        ans += s[i];
    }

    if (!ok)
    {
        ans += (char)('0' + c);
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
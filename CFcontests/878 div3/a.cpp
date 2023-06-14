#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    char pre = '.';

    for (auto & c : s)
    {
        if (pre == '.')
        {
            pre = c;
        } else if (c == pre)
        {
            ans += c;
            pre = '.';
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
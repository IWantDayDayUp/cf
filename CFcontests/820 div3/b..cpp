#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans = "";
    int p = n - 1;
    while (p >= 0)
    {
        if (s[p] == '0')
        {
            int num = s[p - 2] - '0';
            num = num * 10 + s[p - 1] - '0';
            ans += char('a' + num - 1);
            p -= 2;
        } else {
            ans += char('a' + int(s[p] - '0') - 1);
        }
        p -= 1;
    }

    reverse(ans.begin(), ans.end());

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
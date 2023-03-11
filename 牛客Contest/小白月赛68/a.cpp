#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size())
    {
        cout << -1 << endl;
        return;
    }

    string ans = "";
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        int c = (a[i] - '0') * (b[i] - '0');
        ans += to_string(c);
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
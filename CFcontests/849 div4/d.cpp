#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> l, r;
    vector<int> pre(n, 0), suf(n, 0);

    for (int i = 0; i < n; i++)
    {
        l.insert(s[i]);
        pre[i] = l.size();

        suf[n - 1 - i] = r.size();
        r.insert(s[n - 1 - i]);
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pre[i] + suf[i]);
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
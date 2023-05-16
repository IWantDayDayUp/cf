#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 1e9 + 7, t1 = 1e9 + 7, t2 = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int m;
        string s;
        cin >> m >> s;

        if (s == "11")
        {
            ans = min(ans, m);
        } else if (s == "10")
        {
            t1 = min(t1, m);
            ans = min(ans, t1 + t2);
        } else if (s == "01")
        {
            t2 = min(t2, m);
            ans = min(ans, t1 + t2);
        }
    }

    cout << (ans >= 1e9 + 7 ? -1 : ans) << endl;
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;

    reverse(s2.begin(), s2.end());

    string s = s1 + s2;
    int cnt = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cnt += 1;
        }
    }

    cout << (cnt >= 2 ? "NO" : "YES") << endl;
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
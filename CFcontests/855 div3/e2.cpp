#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    vector<int> cnt(26, 0);

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (i >= k || i + k < n)
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        } else {
            ok &= s[i] == t[i];
        }
    }

    cout << (ok && count(cnt.begin(), cnt.end(), 0) == 26 ? "YES" : "NO") << endl;
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
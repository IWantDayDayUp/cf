#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> cnt(26, 0);
    int ans = 0;
    for (auto &c : s)
    {
        if (isupper(c))
        {
            ans += (--cnt[c - 'A']) >= 0;
        } else {
            ans += (++cnt[c - 'a']) <= 0;
        }
    }

    int num = 0;
    for (int i = 0; i < 26; i++)
    {
        num += abs(cnt[i]) / 2;
    }

    cout << ans + min(num, k) << endl;
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
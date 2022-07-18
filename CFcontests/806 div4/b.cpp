#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    int ans = 0;
    for (auto & c : s)
    {
        // cout << c << endl;
        if (cnt[c - 'A'] > 0)
        {
            ans += 1;
        } else {
            ans += 2;
        }
        cnt[c - 'A'] += 1;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}
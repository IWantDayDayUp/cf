#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(10, 0);
    char mx = '9';
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] <= mx)
        {
            cnt[s[i] - '0'] += 1;
            mx = s[i];
        } else {
            cnt[min(s[i] - '0' + 1, 9)] += 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << string(cnt[i], '0' + i);
    }

    cout << endl;
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
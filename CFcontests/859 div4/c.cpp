#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(26), cnt(26);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'a'] += 1;
        cnt[s[i] - 'a'] += i % 2;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0 || cnt[i] == a[i])
        {
        } else {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
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
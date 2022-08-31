#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'R' && t[i] != 'R')
        {
            continue;
        } else if (s[i] == 'R' && t[i] == 'R')
        {
            continue;
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a;
    for (int i = 0; i < n * 2 - 2; i++)
    {
        string s;
        cin >> s;

        if (s.size() == n - 1)
        {
            a.push_back(s);
        }
    }

    reverse(a[0].begin(), a[0].end());

    cout << (a[0] == a[1] ? "YES" : "NO") << endl;
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    transform(s.begin(), s.end(), s.begin(), [](char c)
    {
        return tolower(c);
    });

    s.erase(unique(s.begin(), s.end()), s.end());

    cout << (s == "meow" ? "YES" : "NO") << endl;
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
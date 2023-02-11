#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = n - 1;
    while (l < r)
    {

        if (s[l] != s[r])
        {
            l += 1;
            r -= 1;
        } else {
            break;
        }
    }

    cout << (r - l + 1) << endl;
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
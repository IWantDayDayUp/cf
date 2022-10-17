#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    bool one = false;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num > 0) one = true;
    }

    cout << (one ? "YES" : "NO") << endl;

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
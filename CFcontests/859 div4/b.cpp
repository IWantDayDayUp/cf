#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a % 2 == 0)
        {
            even += a;
        } else {
            odd += a;
        }
    }

    cout << (even > odd ? "YES" : "NO") << endl;
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
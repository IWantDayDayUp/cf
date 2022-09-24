#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0 || j == i - 1)
            {
                cout << 1 << " \n"[j == i - 1];
            } else {
                cout << 0 << ' ';
            }
        }
    }
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
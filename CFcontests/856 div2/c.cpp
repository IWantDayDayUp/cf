#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        while (k <= i && a[i - k] >= k + 1)
        {
            k += 1;
        }
        cout << k << " \n"[i == n - 1];
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
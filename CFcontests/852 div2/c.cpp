#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    int mn = 1, mx = n;

    while (l <= r)
    {
        if (a[l] == mn)
        {
            l += 1;
            mn += 1;
        } else if (a[l] == mx)
        {
            l += 1;
            mx -= 1;
        } else if (a[r] == mn)
        {
            r -= 1;
            mn += 1;
        } else if (a[r] == mx)
        {
            r -= 1;
            mx -= 1;
        } else {
            break;
        }
    }

    if (l <= r)
    {
        cout << l + 1 << ' ' << r + 1 << endl;
    } else {
        cout << -1 << endl;
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
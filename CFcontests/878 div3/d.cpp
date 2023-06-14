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
    sort(a.begin(), a.end());

    int l = 0, r = 1e9 + 7;
    while (l < r)
    {
        int mid = l + r >> 1;

        int i = 0;
        while (i + 1 < n && a[i + 1] - a[0] <= 2 * mid)
        {
            i += 1;
        }

        int j = n - 1;
        while (j - 1 >= 0 && a[n - 1] - a[j - 1] <= 2 * mid)
        {
            j -= 1;
        }

        i++;
        j--;
        if (i > j || a[j] - a[i] <= 2 * mid)
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
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
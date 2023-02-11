#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long sum;
    cin >> n >> sum;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        a[i] += i + 1;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum >= a[i])
        {
            sum -= a[i];
            ans += 1;
        } else {
            break;
        }
    }

    cout << ans << endl;
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
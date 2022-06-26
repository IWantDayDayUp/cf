#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1ll * (d[i]) * (max(0, n - i - 2) - max(0, i - 1));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}
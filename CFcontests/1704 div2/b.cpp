#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    long long l = a[0] - x, r = a[0] + x;

    for (int i = 1; i < n; i++)
    {
        if (r < a[i] - x || l > a[i] + x)
        {
            l = a[i] - x;
            r = a[i] + x;
            ans += 1;
        } else {
            l = max(l, a[i] - x);
            r = min(r, a[i] + x);
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
        slove();
    }

    return 0;
}
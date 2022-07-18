#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    vector<long long> a(n);
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (l == -1 && a[i] > 0 && i < n - 1)
        {
            l = i;
        }
    }

    long long ans = 0;

    if (l == -1)
    {
        cout << 0 << endl;
        return ;
    }
    for (int i = l; i < n - 1; i++)
    {
        if (a[i] > 0)
        {
            ans += a[i];
        } else {
            ans += 1;
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
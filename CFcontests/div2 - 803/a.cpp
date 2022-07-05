#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            cur ^= a[j];
        }
        // cout << cur << endl;

        if (a[i] == cur)
        {
            ans = a[i];
            break;
        }
    }

    // cout << (100 ^ 0) << endl;

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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n >> a;
    vector<int> city(n);
    for (int i = 0; i < n; i++)
    {
        cin >> city[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int l = a - 1 - i;
        int r = a - 1 + i;
        // cout << l << ' ' << r << endl;
        if (l >= 0 && r < n)
        {
            ans += city[l] * city[r] * 2;
        } else if (l >= 0) {
            ans += city[l];
        } else if (r < n) {
            ans += city[r];
        }
    }

    cout << ans + city[a - 1] << endl;

    return 0;
}
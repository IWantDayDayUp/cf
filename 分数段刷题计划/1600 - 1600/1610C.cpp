#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    auto check = [&](int mid)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid - 1 - a[i] <= cnt && cnt <= b[i])
            {
                cnt += 1;
            }
        }
        return cnt >= mid;
    };

    int l = 0, r = n + 1;
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++)
    {
        int idx;
        cin >> idx;
        idx--;

        cnt[idx] += 1;
    }

    auto check = [&](int mid)
    {
        long long time = 0, work = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] >= mid)
            {
                work += cnt[i] - mid;
            } else {
                time += (mid - cnt[i]) / 2;
            }
        }

        return time >= work;
    };

    long long l = *min_element(cnt.begin(), cnt.end());
    long long r = *max_element(cnt.begin(), cnt.end());

    while (l < r)
    {
        long long mid = l + r >> 1;
        if (check(mid))
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
        slove();
    }

    return 0;
}
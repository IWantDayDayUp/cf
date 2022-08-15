#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, h, m, q;
    cin >> n >> h >> m >> q;

    vector<pair<long long, long long>> t1, t2;
    for (int i = 0; i < n; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        t1.push_back({a * m + b, c * m + d});
    }
    sort(t1.begin(), t1.end());

    // vector<pair<long long, long long>> t2;
    t2.push_back(t1[0]);
    for (int i = 1; i < t1.size(); i++)
    {
        if (t1[i].first <= t2.back().second)
        {
            t2.back().second = max(t1[i].second, t2.back().second);
        } else {
            t2.push_back(t1[i]);
        }
    }
    sort(t2.begin(), t2.end());

    for (int i = 0; i < q; i++)
    {
        long long x, y;
        cin >> x >> y;

        long long cur = x * m + y;

        int l = 0, r = t2.size() - 1;
        bool flag = true;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (t2[mid].first <= cur && t2[mid].second >= cur)
            {
                cout << "No" << endl;
                flag = false;
                break;
            } else if (t2[mid].first > cur) {
                r = mid - 1;
            } else if (t2[mid].second < cur)
            {
                l = mid + 1;
            }
        }

        if (flag)
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
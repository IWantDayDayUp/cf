#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        mp[num].emplace_back(i);
    }

    int max = 0, ans = -1, l = -1, r = -1;
    for (auto &p : mp)
    {
        int t = -INT_MAX, pos = -1;
        for (int i = 0; i < p.second.size(); i++)
        {
            if (p.second[i] - 2 * i > t)
            {
                t = p.second[i] - 2 * i;
                pos = p.second[i];
            }

            int cur = 2 * i - p.second[i] + t + 1;
            if (cur > max)
            {
                max = cur;
                ans = p.first;
                l = pos;
                r = p.second[i];
            }
        }
    }

    cout << ans << ' ' << l << ' ' << r << endl;
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
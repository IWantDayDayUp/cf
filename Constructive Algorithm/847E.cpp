#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> p, food;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P') p.emplace_back(i);
        if (s[i] == '*') food.emplace_back(i);
    }

    auto check = [&](int mid)
    {
        int k = 0;
        for (int &x : p)
        {
            int from = x, to = x;
            while (k < food.size())
            {
                from = min(from, food[k]);
                to = max(to, food[k]);
                int need = to - from + min(to - x, x - from);
                if (need > mid)
                {
                    break;
                }
                k += 1;
            }
        }
        return k == food.size();
    };

    int l = 0, r = 3 * n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
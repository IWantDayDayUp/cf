#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> vals(m + 1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= n) continue;

        int l = (a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1));
        int r = min(m + 1, (n - a[i] + i) / (i + 1));

        for (int j = l; j < r; j++)
        {
            vals[j].emplace_back(a[i] + j * (i + 1));
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int sz = vals[i].size();
        vector<bool> exist(sz + 1, false);
        for (auto & v : vals[i])
        {
            if (v < sz) exist[v] = true;
        }

        int ans = 0;
        while (exist[ans]) 
        {
            ans += 1;
        }

        cout << ans << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    map<int, vector<int>> mp;
    int f = -1;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if (f == -1)
        {
            f = c;
        }

        if (c == f || c == t)
        {
            mp[c].push_back(i);
        }
    }

    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    int ans = -1;
    int mx = -1;
    if (mp[t].size() > 0)
    {
        for (auto & num : mp[t])
        {
            if (r[num] > mx)
            {
                ans = num + 1;
                mx = r[num];
            }
        }
    } else {
        for (auto & num : mp[f])
        {
            if (r[num] > mx)
            {
                ans = num + 1;
                mx = r[num];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
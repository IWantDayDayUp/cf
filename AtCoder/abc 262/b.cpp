#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        mp[u].insert(v);
        mp[v].insert(u);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (mp[i].count(j) && mp[j].count(k) && mp[i].count(k))
                {
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
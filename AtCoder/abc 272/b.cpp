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
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int p;
            cin >> p;

            mp[p].insert(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool ok = false;
            for (auto &p : mp[i])
            {
                if (mp[j].count(p))
                {
                    ok = true;
                }
            }

            if (ok == false)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}
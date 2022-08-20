#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    int mx = -1;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;

        mx = max(mx, h);

        mp[h].emplace_back(i);
    }

    // has two or more root node
    if (mp[mx].size() > 1)
    {
        cout << -1 << endl;
        return ;
    }

    // check
    for (int i = 0; i < mx; i++)
    {
        if (mp[i].size() < mp[i + 1].size())
        {
            cout << -1 << endl;
            return ;
        }
    }

    cout << mp[mx].front() << endl;
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < mp[i].size(); j++)
        {
            cout << mp[i][j] << ' ' << mp[i + 1][min(j, (int)mp[i + 1].size() - 1)] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
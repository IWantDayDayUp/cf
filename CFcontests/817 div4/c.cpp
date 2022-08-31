#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string, vector<int>> mp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;

            mp[s].emplace_back(i);
        }
    }

    int a = 0, b = 0, c = 0;
    for (auto & p : mp)
    {
        int cnt = p.second.size();

        if (cnt == 3)
        {
            continue;
        } else if (cnt == 2)
        {
            for (auto & idx : p.second)
            {
                a += (idx == 0) ? 1 : 0;
                b += (idx == 1) ? 1 : 0;
                c += (idx == 2) ? 1 : 0;
            }
        } else {
            a += (p.second[0] == 0) ? 3 : 0;
            b += (p.second[0] == 1) ? 3 : 0;
            c += (p.second[0] == 2) ? 3 : 0;
        }
    }

    cout << a << ' ' << b << ' ' << c << endl;
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
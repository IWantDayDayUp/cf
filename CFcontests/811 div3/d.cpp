#include <bits/stdc++.h>

using namespace std;

void slove() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cur = 0;    
    vector<pair<int, int>> ans;
    while (cur < int(s.size()))
    {
        array<int, 3> temp {cur, -1, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= cur && j + int(a[i].size()) <= s.size(); j++)
            {
                if (s.substr(j, a[i].size()) == a[i])
                {
                    temp = max(temp, array<int, 3> {j + int(a[i].size()), i, j});
                }
            }
        }

        if (temp[0] == cur)
        {
            cout << -1 << endl;
            return ;
        }

        ans.emplace_back(make_pair(temp[1] + 1, temp[2] + 1));

        cur = temp[0];
    }

    cout << ans.size() << endl;
    for (auto & p : ans)
    {
        cout << p.first << ' ' << p.second << endl;
    }
    
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
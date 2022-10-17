#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(50 + 1);
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;

        a[cur].emplace_back(i);
    }

    string s;
    cin >> s;

    for (int i = 1; i <= 50; i++)
    {
        if (a[i].size() == 0) continue;
        for (int j = 1; j < a[i].size(); j++)
        {
            if (s[a[i][0]] != s[a[i][j]])
            {
                cout << "NO" << endl;
                return ;
            }
        }
    }

    cout << "YES" << endl;
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
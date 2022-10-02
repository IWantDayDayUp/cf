#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a, b(n);
    int k = 0;
    vector<vector<int>> ch(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        ch[b[i]].emplace_back(i + 1);

        k += b[i] > i + 1;
    }

    int x = 0;
    if (ch[x].empty())
    {
        x = n + 1;
    }

    int cnt = 0;
    while (cnt < n)
    {
        cnt += ch[x].size();
        for (auto &p : ch[x])
        {
            if (!ch[p].empty())
            {
                swap(p, ch[x].back());
            }
        }
        a.insert(a.end(), ch[x].begin(), ch[x].end());
        x = ch[x].back();
    }

    cout << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
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
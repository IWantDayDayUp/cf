#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<long long>> b(2);
    long long l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;

        b[a[i]].emplace_back(num);
        if (a[i]) 
        {
            r += num;
        } else {
            l += num;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    if (b[0].size() == b[1].size())
    {
        cout << (l + r) * 2 - min(b[0][0], b[1][0]) << endl;
        return;
    }

    if (b[0].size() > b[1].size())
    {
        swap(b[0], b[1]);
        swap(l, r);
    }

    int cnt = b[0].size();
    long long temp = 0;
    for (int i = b[1].size() - cnt; i < b[1].size(); i++)
    {
        temp += b[1][i];
    }

    cout << l + r + l + temp << endl;
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
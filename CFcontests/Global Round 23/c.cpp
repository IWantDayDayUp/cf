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

    vector<pair<int, int>> ans{make_pair(0, -1)};
    for (int i = 0; i < n - 1; i++)
    {
        ans.emplace_back(make_pair(a[i] - a[i + 1], i));
    }
    sort(ans.begin(), ans.end());

    for (auto & p : ans)
    {
        cout << p.second + 2 << ' ';
    }
    cout << endl;
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
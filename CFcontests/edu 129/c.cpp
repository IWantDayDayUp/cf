#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]))
            {
                ans.emplace_back(make_pair(i, j));
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }

    assert(is_sorted(a.begin(), a.end()));
    if (is_sorted(b.begin(), b.end()))
    {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
        }
    } else {
        cout << -1 << endl;
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
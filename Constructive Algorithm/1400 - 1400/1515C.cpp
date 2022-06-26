#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m, x;
    cin >> n >> m >> x;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < m; i++)
    {
        q.emplace(make_pair(0, i + 1));
    }

    vector<int> ans(n, 0);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        auto p = q.top();
        q.pop();

        q.emplace(make_pair(p.first + num, p.second));
        ans[i] = p.second;
        mx = max(mx, p.first + num);
    }

    if (q.top().first + x < mx)
    {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
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
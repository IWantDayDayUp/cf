#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> q;
    for (int i = 1; i <= n; i++)
    {
        q.emplace(i);
    }

    vector<pair<int, int>> ans;
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        int cur = (a + b + 1) / 2;
        q.emplace(cur);

        ans.emplace_back(make_pair(a, b));
    }

    cout << q.top() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
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
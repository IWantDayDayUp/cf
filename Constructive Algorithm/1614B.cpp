#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        q.emplace(make_pair(cur, i + 1));
    }
    vector<int> ans(n + 1);
    ans[0] = 0;
    int l = -1, r = 1;
    long long total = 0;
    while (!q.empty())
    {
        int cur = q.top().second;
        int cnt = q.top().first;
        q.pop();
        if (r - ans[0] <= ans[0] - l)
        {
            ans[cur] = r;
            total += abs(r - ans[0]) * cnt * 2;
            r += 1;
        } else {
            ans[cur] = l;
            total += abs(r - ans[0]) * cnt * 2;
            l -= 1;
        }
    }

    cout << total << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
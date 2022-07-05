#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

static bool cmp(pair<int, int>& m, pair<int, int>& n) 
{
    long long l1 = m.second - m.first + 1;
    long long l2 = n.second - n.first + 1;
    if (l1 == l2)
    {
        return m.first > n.first;
    }
    return l1 < l2;
}

void slove() {
    int n;
    cin >> n;

    // pair: [left, right]
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    q.emplace(make_pair(1, n));

    vector<long long> ans(n + 1, 0);
    long long cnt = 0;
    while (!q.empty())
    {
        int l = q.top().first, r = q.top().second;
        q.pop();

        long long p = 0;
        if ((r - l + 1) % 2 == 0)
        {
            p = (l + r - 1) / 2;
        } else {
            p = (l + r) / 2;
        }
        ans[p] = ++cnt;

        if (l <= p - 1) 
        {
            q.emplace(make_pair(l, p - 1));
        }   
        if (p + 1 <= r)
        {
            q.emplace(make_pair(p + 1, r));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
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
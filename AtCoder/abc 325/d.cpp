#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        long long t, d;
        cin >> t >> d;

        v.emplace_back(t, t + d);
    }
    sort(v.begin(), v.end());

    priority_queue<long long, vector<long long>, greater<>> pq;

    int idx = 0;
    int ans = 0;

    for (long long i = 0; ; i++)
    {
        if (pq.empty())
        {
            if (idx >= n) break;
            i = v[idx].first;
        }

        while (idx < n && v[idx].first == i)
        {
            pq.emplace(v[idx++].second);
        }

        while (!pq.empty() && pq.top() < i)
        {
            pq.pop();
        }

        if (!pq.empty())
        {
            pq.pop();
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
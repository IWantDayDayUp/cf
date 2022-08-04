#include <bits/stdc++.h>

using namespace std;

void slove() {
    long long n, m;
    cin >> n >> m;

    vector<long long> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    priority_queue<long long, vector<long long>, less<long long>> q;
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            q.emplace(n - 1 - p[i] + p[0]);
        } else {
            q.emplace(p[i + 1] - p[i] - 1);
        }
    }

    long long ans = 0;
    long long cnt = 0;
    while (!q.empty())
    {
        long long cur = q.top();
        q.pop();

        // cout << "cur: " << cur << endl;

        cur -= 4 * cnt;
        if (cur <= 0)
        {
            break;
        }

        if (cur > 1)
        {
            ans += cur - 1;
        } else {
            ans += cur;
        }
        // ans += cur - 1;

        cnt += 1;
    }

    cout << n - ans << endl;
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
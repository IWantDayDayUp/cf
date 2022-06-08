#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<i64> s(n), f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    deque<int> q;
    i64 t = 0;
    vector<i64> ans(n, 0);
    int i = 0;
    while (!q.empty() || i < n)
    {
        if (q.empty() && t < s[i])
        {
            t = s[i];
        }
        while (i < n && s[i] <= t)
        {
            q.emplace_back(i);
            i += 1;
        }
        int cur = q.front();
        q.pop_front();

        ans[cur] = f[cur] - t;

        t = f[cur];
    }

    for (int i = 0; i < n; i++)
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
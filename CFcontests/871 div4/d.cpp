#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == m)
        {
            cout << "YES" << endl;
            return ;
        } else if (cur > m && cur % 3 == 0)
        {
            int mn = cur / 3, mx = 2 * mn;

            if (mn >= m)
            {
                q.push(mn);
            }

            if (mx >= m)
            {
                q.push(mx);
            }
        }
    }

    cout << "NO" << endl;
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
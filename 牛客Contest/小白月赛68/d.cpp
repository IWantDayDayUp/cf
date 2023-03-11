#include <bits/stdc++.h>

using namespace std;

void solve() {
    int dx[7] = {1, -1, 10, -10, 100, -100, 300};

    queue<int> q;
    q.push(10);
    
    vector<int> vis(500 + 5);
    vis[10] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < 7; i++)
        {
            int nv = v + dx[i];

            nv = min(nv, 300);
            nv = max(nv, 10);

            if (!vis[nv])
            {
                vis[nv] = vis[v] + 1;
                q.push(nv);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;

        ans += vis[n] - 1;
    }

    cout << ans << endl;
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
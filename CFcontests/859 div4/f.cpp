#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;

    string s;
    cin >> s;

    int dir = s[0] == 'U' ? 1 + (s[1] == 'R' ? 2 : 0) : 0 + (s[1] == 'R' ? 2 : 0);

    bool vis[n][m][4];
    memset(vis, false, sizeof(vis));

    int x = x1, y = y1;
    int ans = 0;

    while (!vis[x][y][dir])
    {
        // if end?
        if (x == x2 && y == y2) 
        {
            cout << ans << endl;
            return ;
        }

        // change dir
        int cur = 0;
        if (dir % 2 == 1 && x == 0)
        {
            dir -= 1;
            cur += 1;
        }
        if (dir % 2 == 0 && x == n - 1)
        {
            dir += 1;
            cur += 1;
        }
        if (dir >= 2 && y == m - 1)
        {
            dir -= 2;
            cur += 1;
        }
        if (dir < 2 && y == 0)
        {
            dir += 2;
            cur += 1;
        }
        ans += min(1, cur);

        // if continue?
        if (vis[x][y][dir])
        {
            break;
        }
        vis[x][y][dir] = true;

        // update (x, y)
        if (dir % 2 == 1)
        {
            x--;
        } else {
            x++;
        }
        if (dir >= 2)
        {
            y++;
        } else {
            y--;
        }
    }

    cout << -1 << endl;
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
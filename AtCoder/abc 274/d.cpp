#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    // x += 1e4;
    // y += 1e4;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int mod = 2 * 1e4;

    queue<pair<int, int>> q;
    q.emplace(make_pair((0 + 1e4) * mod+ (0 + a[1] + 1e4), 1));

    int k = 1;

    while (k <= n)
    {
        k += 1;

        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            int curX = q.front().first / mod, curY = q.front().first % mod;
            int dir = q.front().second;
            q.pop();

            // cout << k << ' ' << curX - 1e4 << ' ' << curY - 1e4 << ' ' << dir << endl;

            if (k == n + 1 && curX - 1e4 == y && curY - 1e4 == x)
            {
                cout << "Yes" << endl;
                return 0;
            }

            if (dir == 1)
            {
                int nx = curX + a[k], ny = curY;
                if (0 <= nx && nx < 2 * 1e4 && 0 <= ny && ny < 2 * 1e4)
                {
                    q.emplace(make_pair(nx * mod + ny, 0));
                }

                nx = curX - a[k];
                ny = curY;
                if (0 <= nx && nx < 2 * 1e4 && 0 <= ny && ny < 2 * 1e4)
                {
                    q.emplace(make_pair(nx * mod + ny, 0));
                }
            } else {
                int nx = curX, ny = curY + a[k];
                if (0 <= nx && nx < 2 * 1e4 && 0 <= ny && ny < 2 * 1e4)
                {
                    q.emplace(make_pair(nx * mod + ny, 1));
                }

                nx = curX;
                ny = curY - a[k];
                if (0 <= nx && nx < 2 * 1e4 && 0 <= ny && ny < 2 * 1e4)
                {
                    q.emplace(make_pair(nx * mod + ny, 1));
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    long long ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                queue<pair<int, int>> q;
                q.emplace(i, j);

                while (!q.empty())
                {
                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && nx < h && ny >= 0 && ny < w)
                            {
                                if (s[nx][ny] == '#')
                                {
                                    s[nx][ny] = '.';
                                    q.emplace(nx, ny);
                                }
                            }
                        }
                    }
                }

                ans += 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
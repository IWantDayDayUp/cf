#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vector<string> g(H);
    for (auto &x : g)
        cin >> x;

    auto ok = [&](int i, int j)
    {
        return 0 <= i and i < H and 0 <= j and j < W;
    };

    auto test = [&](int i, int j, int d)
    {
        for (auto &x : vector{+d, -d})
        {
            for (auto &y : vector{+d, -d})
            {
                int s = i + x, t = j + y;
                if (!ok(s, t) or g[s][t] != '#')
                    return false;
            }
        }
        return true;
    };

    int N = min(H, W);
    vector<int> ans(N + 1);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (g[i][j] != '#')
                continue;

            if (test(i, j, 1))
            {
                int d = 1;
                while (test(i, j, d + 1))
                    d++;
                ans[d]++;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
        cout << ans[i] << " \n"[i == N];

    return 0;
}
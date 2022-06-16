/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 0);

        vector<int> dis(n * m, INT_MAX / 2);
        dis[0] = 0;

        auto check = [&](int x, int y)
        {
            return x >= 0 and x < m and y >= 0 and y < n;
        };

        while (!q.empty())
        {
            int curdis = q.top().first;
            int x = q.top().second / n, y = q.top().second % n;
            q.pop();

            if (curdis > dis[x * n + y])
            {
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (check(nx, ny))
                {
                    int need = grid[nx][ny];
                    if (curdis + need < dis[nx * n + ny])
                    {
                        dis[nx * n + ny] = curdis + need;
                        q.emplace(curdis + need, nx * n + ny);
                    }
                }
            }
        }

        return dis[n * m - 1];
    }
};
// @lc code=end

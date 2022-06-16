/*
 * @lc app=leetcode.cn id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // pair.first: cur dis
        // pair.second: x * n + y
        q.emplace(0, 0);
        vector<int> dis(m * n, INT_MAX / 2);
        // 0 = 0 * n + 0
        dis[0] = 0;

        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int curdis = q.top().first;
            int x = q.top().second / n, y = q.top().second % n;
            q.pop();

            int num = grid[x][y];

            if (curdis > dis[x * n + y]) continue;
            for (int i = 0; i < 4; i++)
            {
                int w = num == (i + 1) ? 0 : 1;
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (curdis + w < dis[nx * n + ny])
                {
                    dis[nx * n + ny] = curdis + w;
                    q.emplace(curdis + w, nx * n + ny);
                }
            }

        }

        return dis[m * n - 1];
    }
};
// @lc code=end


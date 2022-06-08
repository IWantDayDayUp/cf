# 0-1 BFS

## 1. 0-1 BFS

[0-1 BFS 教程 - codeforces](https://codeforces.com/blog/entry/22276)

## 1368: 使网格图至少有一条有效路径的最小代价

## 6081: 到达角落需要移除障碍物的最小数目

```c++
using PII = pair<int, int>;

class Solution {
private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m * n, INT_MAX);
        vector<int> seen(m * n, 0);
        dist[0] = 0;
        deque<int> q;
        q.push_back(0);
        while(!q.empty()) {
            auto cur_pos = q.front();
            q.pop_front();
            if(seen[cur_pos]) {
                continue;
            }
            seen[cur_pos] = 1;
            int x = cur_pos / n;
            int y = cur_pos % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                int new_pos = nx * n + ny;
                int new_dis = dist[cur_pos] + (grid[x][y] == 1);
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && new_dis < dist[new_pos]) {
                    dist[new_pos] = new_dis;
                    if (grid[x][y] == 0) {
                        q.push_front(new_pos);
                    }else {
                        q.push_back(new_pos);
                    }
                }
            }
        }

        return dist[m * n - 1];
    }
};
```

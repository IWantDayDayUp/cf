# DFS 时间戳

## 1.何为时间戳?

我们可以在 DFS 一棵树的过程中, 维护一个全局的时间戳 `clock`, 每访问一个新的节点, 就将 `clock` 加一

同时, 记录进入节点 x 时的时间戳 `in[x]`, 和离开(递归结束)这个节点时的时间戳 `out[x]`

## 2.性质?

当我们递归以 x 为根的子树时, 设 y 是以 xx 为根的子树中的一个节点, 那么我们必须先递归完以 y 为根的子树, 之后才能递归完以 x 为根的子树

从时间戳上看, 如果 y 是以 x 为根的子树中的一个节点, 那么区间 `[in[y], out[y]]` 必然被区间 `[in[x], out[x]]` 所包含

反之, 如果区间 `[in[y],out[y]]` 被区间 `[in[x],out[x]]` 所包含, 那么 y 必然是以 x 为根的子树中的一个节点

## 3.应用

来自: 第 `299` 场周赛第四题

- 1. [6103.从树中删除边的最小分数](https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/)

DFS时间戳:

```c++
    vector<vector<int>> adj(n);
    for (auto & e : edges)
    {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }

    int clock = 0;
    // 进入子树的时间, 离开子树的时间
    vector<int> in(n), out(n);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        in[u] = ++clock;
        for (auto & v : adj[u])
        {
            if (v == p) continue;
            dfs(v, u);
        }
        out[u] = clock;
    };

    dfs(0, -1);
```

完整代码:

```c++
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<vector<int>> adj(n);
        for (auto & e : edges)
        {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        int clock = 0;
        vector<int> in(n), out(n);
        vector<int> nor(n, 0);
        
        function<void(int, int)> dfs = [&](int u, int p)
        {
            in[u] = ++clock;
            nor[u] = nums[u];
            for (auto & v : adj[u])
            {
                if (v == p) continue;
                dfs(v, u);
                nor[u] ^= nor[v];
            }
            out[u] = clock;
        };

        dfs(0, -1);

        auto is_parent = [&](int x, int y) -> bool {
            return in[x] <= in[y] && in[y] <= out[x];
        };

        for (auto &e : edges)
        {
            if (!is_parent(e[0], e[1]))
            {
                swap(e[0], e[1]);
            } 
        } 

        int ans = INT_MAX;
        for (int i = 0; i < edges.size(); ++i) {
            int x1 = edges[i][0], y1 = edges[i][1];
            for (int j = 0; j < i; ++j) {
                int x2 = edges[j][0], y2 = edges[j][1];

                int x, y, z; 
                
                if (is_parent(y1, x2))
                {
                    // y1 是 x2 的父节点（或重合）
                    x = nor[y2];
                    y = nor[y1] ^ nor[y2];
                    z = nor[0] ^ nor[y1];
                } 
                else if (is_parent(y2, x1)) {
                    // y2 是 x1 的父节点（或重合）
                    x = nor[y1];
                    y = nor[y2] ^ nor[y1];
                    z = nor[0] ^ nor[y2];
                }
                else {
                    // 删除的两条边分别属于两颗不相交的子树
                    x = nor[y1];
                    y = nor[y2];
                    z = nor[0] ^ nor[y1] ^ nor[y2];
                }

                ans = min(ans, max({x, y, z}) - min({x, y, z}));
            }
        }
        return ans;
    }
};
```

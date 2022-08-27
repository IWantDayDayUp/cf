# Dijkstra

## 1. 暴力法 - 适用于稠密图

```c++
    int n = 1000, k = 3;
    const int inf = INT_MAX / 2;
    // 任意两个节点的初始距离是: 无穷大
    vector<vector<int>> adj(n, vector<int>(n, inf));
    // 直接相连的节点, 距离设为链路权重
    for (auto & e : edges)
    {
        adj[e[0]][e[1]] = e[2];
    }

    // 存储从 k 到每个节点的初始距离, 初始为无穷大
    vector<int> dis(n, inf);
    dis[k - 1] = 0;
    // 表示该节点是否已经被确定最短距离, false表示没有
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        // 从所有未被确定最短距离的节点里, 挑选出距离k最近的节点x
        int x = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (x == -1 || dis[j] < dis[x]))
            {
                x = j;
            }
        }
        // 不确定节点x -> 确定节点x
        visited[x] = true;
        // 以这个节点x为跳板, 更新所有节点到节点k的最短距离
        for (int j = 0; j < n; j++)
        {
            dis[j] = min(dis[j], dis[x] + adj[x][j]);
        }
    }
```

## 2. 优先队列 - 适用于稀疏图

```c++
int n = 1000, k = 3;
vector<int> dis(n, 1e9);
// 自己到自己, 距离为0
dis[k - 1] = 0;

// 邻接矩阵
vector<vector<pair<int, int>>> adj(n + 1);
for (auto & e : edges)
{
    adj[e[0]].emplace_back(make_pair(e[1], e[2]));
    adj[e[1]].emplace_back(make_pair(e[0], e[2]));
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
q.emplace(0, k);

while (!q.empty())
{
    int curdis = q.top().first, u = q.top().second;
    q.pop();

    if (curdis > dis[u]) continue;
    // 遍历以 cur 为起点的edge, 做松弛, 并将松弛之后的终点入队
    for (auto e : adj[u])
    {
        int v = e.first, w = e.second;
        if (dis[v] > dis[u] + w)
        {
            dis[v] = dis[u] + w;
            q.emplace(dis[v], v);
        }
    }
}
```

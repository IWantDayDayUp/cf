# abc 259 F - Select Edges

## 1. 题目

一棵树有 $n$ 个节点, $n - 1$ 条边, 每条边连接节点 $u_i$ 和 $v_i$, 权重为 $w_i$

现在需要从 $n - 1$ 条边中选择若干条(可以为0), 使得所有被选择的边的 `权重和最大`

对于每个节点(1, ..., n)来说, 最多选择 $d_i$ 条邻接边

## 2. 分析

对于节点 `v`, 定义如下:

* $dp_{<=}[v]$: 从子树 $v$ 中选择 `至多` $d_v$ 条 $v$ 的邻接边, 所能得到的最大权重和

* $dp_{<}[v]$: 从子树 $v$ 中选择 `严格小于` $d_v$ 条 $v$ 的邻接边, 所能得到的最大权重和

对于节点 $v$ 的每一条邻接边 $(v, u)$, 有两种情况:

* 选择: 由于边 $(v, u)$ 占用节点 $u$ 的名额, 对子树 $u$ 来说, 此时只能选择 `严格小于` $d_u$ 条邻接边, 即: $dp_{<}[u]$

  此时, 节点 $v$ 从子树 $v$ 中能获得的最大权重和为: $S_u = w + dp_{<}[u]$

* 不选择: 边 $(v, u)$ 不会占用名额, 子树 $u$ 仍然可以选择至多 $d_u$ 条邻接边
  
  此时的最大权重和为: $S_u = dp_{<=}[u]$

因此, 该问题可以等价于: 
> 对于 节点 $v$ 的所有子节点, 可以执行选择上述两个操作(操作1为选择, 操作2为不选择), 并且操作1至多可以选择 $d_v$ 次, 求可以得到的最大权重和

对于节点 $v$ 的某个子节点 $u$ 来说, 若刚开始选择 `操作2`, 即: 不选边$(v, u)$, 然后转而选择 `操作1`, 即: 选择边$(v, u)$, (其他子节点操作不变)

此时, 子树 $u$ 的最大权重和 $S_u$ 的变化量为: $\Delta = w + dp_{<}[u] - dp_{<=}[u]$

为了解决上述问题, 可以将 $v$ 的所有子节点初始都选择 `操作2`, 然后依次更改为 `操作1`, 并记录其最大权重和的变化量 $\Delta$

然后, 贪心地选择: 1. 变化量较大且大于0  2. 操作更改不超过 $d_v$ 次

另外, 存在特殊情况, 当 $d_v == 0$:

* $dp_{<=}[v]$: 选择的边数可以 `<=` 0, 结果为 $0$

* $dp_{<}[v]$: 选择的边数不可以 `严格小于` 0, 结果为 $-inf$

## 3. 代码

```c++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        adj[x].emplace_back(make_pair(y, z));
        adj[y].emplace_back(make_pair(x, z));
    }

    const long long inf = (long long)1e18;
    // dp[i][0]: 选择的边数 `严格小于` d_i
    // dp[i][1]: 选择的变数 `小于等于` d_i
    vector<vector<long long>> dp(n, vector<long long>(2, 0));

    function<void(int, int)> dfs = [&](int u, int p)
    {
        // 对于子节点 u 来说, 它最多选 d_u 条邻接边
        // 对于节点 u 的所有邻接边来说, 都有两个选择:
        // 1. 选(最多选d_u条)
        // 2. 不选

        // 对于节点 u 的某个子节点 v 来说, 边(u, v)有两种情况:

        // 1. 选
        // sum_u = dp[v][0] + w (因为边(u, v)占用一条边, 节点v最多选择 `d_v - 1` 条)


        // 2. 不选
        // sum_u = dp[v][0] (边(u, v)不占用名额, 节点v最多选择 `d_v` 条边)

        // 因此: 对于边(u, v)来说:
        // 不选 -> 选 引起的sum变化量为: dp[v][0] + w - dp[v][1]
        // 记录所有子节点引起的变化量:
        // 只选: 1. 变化量大于0   2. 最多d_u个

        vector<long long> vec;
        for (auto & pa : adj[u])
        {
            int v = pa.first, w = pa.second;
            if (v == p) continue;
            dfs(v, u);

            // 记录变化量
            vec.emplace_back(dp[v][0] + w - dp[v][1]);

            // 初始, 不选边(u, v), 后面再根据变化量将 `不选` 改为 `选`
            dp[u][0] += dp[v][1];
            dp[u][1] += dp[v][1];
        }

        // 按变化量, 降序
        sort(vec.rbegin(), vec.rend());

        for (int i = 0; i < (int)vec.size(); i++)
        {
            // 只选变化量大于0的(题目问最大)
            if (vec[i] <= 0) break;

            // dp[u][0]: 邻接边的选择数量 `严格小于` d_u (因为边(u父节点, u)占用名额)
            if (i < d[u] - 1)
            {
                dp[u][0] += vec[i];
            }
            // dp[u][1]: 邻接边的选择数量 `小于等于` d_u
            if (i < d[u])
            {
                dp[u][1] += vec[i];
            }
        }

        // 节点 u 一条邻接边都不能选
        if (d[u] == 0)
        {
            dp[u][0] = -inf;
        }
    };

    dfs(0, -1);

    cout << dp[0][1] << endl;
    
    return 0;
}

```

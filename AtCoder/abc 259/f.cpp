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

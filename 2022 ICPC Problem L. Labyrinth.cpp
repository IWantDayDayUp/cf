#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // n 个位置, m 条单向边, s 是出发点
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        // 单向边, u -> v
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        // 为啥 v != s ??
        if (v != s)
        {
            adj[u].push_back(v);
        }
    }

    // last: 存储每个点的父亲节点, -1 表示没有父亲节点
    // st: (可能)存储该节点属于哪条path
    std::vector<int> last(n, -1), st(n, -1);

    // dfs
    auto dfs = [&](auto self, auto u) -> void
    {
        for (auto v : adj[u])
        {
            // -1: 表示没有被搜索过
            if (st[v] == -1)
            {
                // 节点v 和 节点u 属于一条path
                st[v] = st[u];
                last[v] = u;  // 父节点

                // 继续搜
                self(self, v);  
            }
            // 该节点已经被其他path经过了
            // 那不就说明有两条path, 最后都到达节点 v
            // 直接输出结果
            else if (st[v] != st[u])
            {
                std::cout << "Possible\n";

                // 根据 last存储的父亲节点信息, 逆向, 构建path
                std::vector<int> a, b{v};
                for (auto i = v; i != -1; i = last[i])
                {
                    a.push_back(i);
                }
                for (auto i = u; i != -1; i = last[i])
                {
                    b.push_back(i);
                }
                std::reverse(a.begin(), a.end());
                std::reverse(b.begin(), b.end());

                //
                std::cout << a.size() << "\n";
                for (auto x : a)
                {
                    std::cout << x + 1 << " \n"[x == v];
                }
                std::cout << b.size() << "\n";
                for (auto x : b)
                {
                    std::cout << x + 1 << " \n"[x == v];
                }
                std::exit(0);
            }
        }
    };

    for (auto v : adj[s])
    {
        // 节点 s 的所有子节点都指向 s
        last[v] = s;
        // 节点 v 是属于 v这条path
        st[v] = v;
    }

    // 
    for (auto v : adj[s])
    {
        dfs(dfs, v);
    }

    std::cout << "Impossible\n";

    return 0;
}
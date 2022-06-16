# DSU 并查集

## 1. 模板

```c++
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    void init(int k)
    {
        // 0 or 1-index ?
        parent.resize(k + 1);
        for (int i = 0; i <= k; ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void to_union(int x, int y)
    {
        parent[find(x)] = find(y);
    }
    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
};
```

## 2. 使用

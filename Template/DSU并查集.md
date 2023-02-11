# DSU 并查集

## 1. 模板

```c++
#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> p, siz;

    DSU(int n) : p(n), siz(n, 1)
    {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
        {
            return false;
        }

        siz[x] += siz[y];
        p[y] = x;

        return true;
    }

    int size(int x)
    {
        return siz[p[x]];
    }
};
```

## 2. 使用

codeforces 1609

```c++
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct DSU {
    vector<int> parent, cnt;
    DSU(int n) : parent(n), cnt(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int get_parent(int x)
    {
        while (x != parent[x])
        {
            x = parent[x];
            parent[x] = parent[parent[x]];
        }

        return x;
    }

    bool is_conect(int a, int b)
    {
        return get_parent(a) == get_parent(b);
    }

    bool update(int a, int b)
    {
        int pa = get_parent(a);
        int pb = get_parent(b);
        if (pa == pb) return false;
        cnt[pa] += cnt[pb];
        parent[pb] = pa;
        return true;
    }

    int size(int x)
    {
        return cnt[get_parent(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    DSU dsu(n);
    int temp = 0;
    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (!dsu.update(x, y))
        {
            temp += 1;
        }

        vector<int> a;
        for (int idx = 0; idx < n; idx++)
        {
            if (dsu.get_parent(idx) == idx)
            {
                a.emplace_back(dsu.size(idx));
            }
        }
        sort(a.begin(), a.end(), greater<int>());

        cout << accumulate(a.begin(), a.begin() + temp + 1, 0) - 1 << endl;
    }

    return 0;
}
```

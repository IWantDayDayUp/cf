#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> a, b;
    vector<int> p;

    DSU(int n, int m)
    {
        a.resize(n + m, 0);
        b.resize(n + m, 0);
        p.resize(n + m, -1);

        for (int i = 0; i < n; i++)
        {
            a[i] = 1;
        }
        for (int i = n; i < n + m; i++)
        {
            b[i] = 1;
        }
    }

    int root(int x)
    {
        if (p[x] == -1)
        {
            return x;
        } else {
            p[x] = root(p[x]);
            return p[x];
        }
    }

    bool connect(int x, int y)
    {
        return root(x) == root(y);
    }

    int get_a(int x)
    {
        return a[root(x)];
    }

    int get_b(int x)
    {
        return b[root(x)];
    }

    void to_union(int x, int y)
    {
        int px = root(x);
        int py = root(y);

        p[px] = py;
        a[py] += a[px];
        b[py] += b[px];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, e;
    cin >> n >> m >> e;

    vector<int> u(e), v(e);
    for (int i = 0; i < e; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    int q;
    cin >> q;
    vector<int> x(q);
    vector<bool> ok(e, true);
    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
        x[i]--;

        ok[x[i]] = false;
    }

    DSU dsu(n, m);
    int cnt = 0;

    for (int i = 0; i < e; i++)
    {
        if (ok[i])
        {
            if (!dsu.connect(u[i], v[i]))
            {
                int ua = dsu.get_a(u[i]);
                int va = dsu.get_a(v[i]);

                int ub = dsu.get_b(u[i]);
                int vb = dsu.get_b(v[i]);

                if (ub > 0 && vb == 0)
                {
                    cnt += va;
                }

                if (ub == 0 && vb > 0)
                {
                    cnt += ua;
                }

                dsu.to_union(u[i], v[i]);
            }
        }
    }

    vector<int> ans(q);
    for (int i = q - 1; i >= 0; i--)
    {
        ans[i] = cnt;

        if (!dsu.connect(u[x[i]], v[x[i]]))
        {
            int ua = dsu.get_a(u[x[i]]);
            int va = dsu.get_a(v[x[i]]);

            int ub = dsu.get_b(u[x[i]]);
            int vb = dsu.get_b(v[x[i]]);

            if (ub > 0 && vb == 0){
                cnt += va;
            }
            if (vb > 0 && ub == 0){
                cnt += ua;
            }

            dsu.to_union(u[x[i]], v[x[i]]);
        }
    }

    for (auto & num : ans)
    {
        cout << num << endl;
    }

    return 0;
}
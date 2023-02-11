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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = 0;

    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        cnt += dsu.merge(u, v);
    }

    cout << m - cnt << endl;

    return 0;
}
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        dsu.merge(u, v);
    }

    int k;
    cin >> k;

    set<pair<int, int>> st;

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        int x = dsu.find(u);
        int y = dsu.find(v);
        if (x > y)
        {
            swap(x, y);
        }
        st.insert(make_pair(x, y));
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        int x = dsu.find(u);
        int y = dsu.find(v);
        if (x > y)
        {
            swap(x, y);
        }

        cout << (!st.count(make_pair(x, y)) ? "Yes" : "No") << endl;
    }

    return 0;
}
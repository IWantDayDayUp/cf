#include <bits/stdc++.h>

using namespace std;

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

    int n, m;
    long long c;
    cin >> n >> m >> c;

    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }
    sort(a.begin(), a.end());

    auto check = [&](int mid)
    {
        long long cur = c, sum = 0;

        DSU dsu(n + 1);

        for (auto & [w, u, v] : a)
        {
            // cout << w << ' ' << u << ' ' << v << endl;
            if (w > mid)
            {
                if (!dsu.is_conect(u, v))
                {
                    dsu.update(u, v);

                    sum += w;
                    cur -= sum;

                    if (cur < 0)
                    {
                        return false;
                    }
                }
            } else {
                dsu.update(u, v);
            }
        }

        return true;
    };

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        // cout << mid << endl;
        if (check(mid))
        {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
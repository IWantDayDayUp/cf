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

    void update(int a, int b)
    {
        int pa = get_parent(a);
        int pb = get_parent(b);
        // cnt[pa] += cnt[pb];
        parent[pb] = pa;
        // return true;
    }

    int size(int x)
    {
        return cnt[get_parent(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<long long> x(n), y(n), r(n);
    int f1 = -1, f2 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
        if ((x1 - x[i]) * (x1 - x[i]) + (y1 - y[i]) * (y1 - y[i]) == r[i] * r[i])
        {
            f1 = i;
        }
        if ((x2 - x[i]) * (x2 - x[i]) + (y2 - y[i]) * (y2 - y[i]) == r[i] * r[i])
        {
            f2 = i;
        }
    }

    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long rr = dx * dx + dy * dy;
            if (rr <= (r[i] + r[j]) * (r[i] + r[j]) && rr >= (r[i] - r[j]) * (r[i] - r[j]))
            {
                dsu.update(i, j);
            }
        }
    }

    if (dsu.is_conect(f1, f2))
    {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
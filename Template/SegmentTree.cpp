#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int l, r;
    int val, add;
} tr[10000];

class Solution
{
public:
    void pushup(int u)
    {
        tr[u].val = max(tr[u << 1].val, tr[u << 1 | 1].val);
    }
    void pushdown(int u)
    {
        if (tr[u].add)
        {
            tr[u << 1].add = 1;
            tr[u << 1 | 1].add = 1;
            tr[u << 1].val = tr[u << 1 | 1].val = tr[u].val;
            tr[u].add = 0;
        }
    }
    void build(int u, int l, int r)
    {
        if (l == r)
            tr[u] = {l, r, 0, 0};
        else
        {
            tr[u] = {l, r, 0, 0};
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushup(u);
        }
    }
    void update(int u, int l, int r, int v)
    {
        if (tr[u].l >= l && tr[u].r <= r)
        {
            tr[u].add = 1;
            tr[u].val = v;
        }
        else
        {
            pushdown(u);
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (l <= mid)
                update(u << 1, l, r, v);
            if (r > mid)
                update(u << 1 | 1, l, r, v);
            pushup(u);
        }
    }
    int query(int u, int l, int r)
    {
        if (tr[u].l >= l && tr[u].r <= r)
            return tr[u].val;
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 0;
        if (l <= mid)
            res = max(res, query(u << 1, l, r));
        if (r > mid)
            res = max(res, query(u << 1 | 1, l, r));
        return res;
    }
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        set<int> arr;
        for (auto p : positions)
        {
            arr.insert(p[0]);
            arr.insert(p[0] + p[1] - 1);
        }
        int n = 0;
        unordered_map<int, int> S;
        for (auto p : arr)
            S[p] = ++n;
        build(1, 1, n);
        vector<int> res(positions.size());
        for (int i = 0; i < positions.size(); i++)
        {
            int l = S[positions[i][0]];
            int r = S[positions[i][0] + positions[i][1] - 1];
            int maxv = query(1, l, r);
            maxv += positions[i][1];
            update(1, l, r, maxv);
            res[i] = tr[1].val;
        }
        return res;
    }
};
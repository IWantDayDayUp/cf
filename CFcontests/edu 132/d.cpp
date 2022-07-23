#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int l, r;
    // 当前区间最大值
    int val;
    // 懒惰标记
    int lazy;
} tr[1000000];

void pushup(int p)
{
    // 子节点更新父节点的最大值
    tr[p].val = max(tr[p << 1].val, tr[p << 1 | 1].val);
}
void pushdown(int p)
{
    // 懒惰标记下放
    if (tr[p].lazy)
    {
        tr[p << 1].lazy = 1;
        tr[p << 1].val = tr[p].val;

        tr[p << 1 | 1].lazy = 1;
        tr[p << 1 | 1].val = tr[p].val;

        tr[p].lazy = 0;
    }
    return;
}
void build(int p, int l, int r)
{
    // 初始化
    if (l == r)
        tr[p] = {l, r, 0, 0};
    else
    {
        tr[p] = {l, r, 0, 0};

        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);

        pushup(p);
    }
}
void update(int p, int l, int r, int val)
{
    // 当前节点的区间是更新区间的子区间
    if (tr[p].l >= l && tr[p].r <= r)
    {
        tr[p].val = val;
        tr[p].lazy = 1;
        return;
    }

    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid)
        update(p << 1, l, r, val);
    if (r > mid)
        update(p << 1 | 1, l, r, val);
    pushup(p);
    return;
}
int query(int p, int l, int r)
{
    // 当前区间是查询区间的子区间
    if (tr[p].l >= l && tr[p].r <= r)
        return tr[p].val;
        
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    int res = 0;
    if (l <= mid)
        res = max(res, query(p << 1, l, r));
    if (r > mid)
        res = max(res, query(p << 1 | 1, l, r));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 线段树
    build(1, 1, m);

    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;

        update(1, i, i, num);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int xs, ys, xt, yt, k;
        cin >> xs >> ys >> xt >> yt >> k;

        if (xs > xt) swap(xs, xt);
        if (ys > yt) swap(ys, yt);

        if (abs(ys - yt) % k != 0 || abs(xs - xt) % k != 0)
        {
            cout << "NO" << endl;
        } else {
            int maxv = query(1, ys, yt);

            if (max(xs, xt) > maxv)
            {
                cout << "YES" << endl;
            } else {
                bool ok = false;
                for (int h = maxv + 1; h <= min(n, maxv + k); h++)
                {
                    if (abs(h - xs) % k == 0 && abs(h - xt) % k == 0)
                    {
                        ok = true;
                        break;
                    }
                }

                if (ok)
                {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}
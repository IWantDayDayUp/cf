/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
private:
    struct Node
    {
        // 左右子节点
        int lc, rc;
        // 当前区间的最大值
        int max;
        // 懒惰标记
        int add;
    };

    // 范围估计
    const static int N = 1e9, M = 4 * 400 * 20;

    // 节点下标
    // 对于节点p来说, 左节点并不一定是(2*p), 右节点也不一定是(2*p + 1)
    int cnt = 1;
    Node tr[M] = {{0, 0, 0, 0}};

    void update(int p, int lc, int rc, int l, int r, int val)
    {
        // p: 当前节点的编号
        // [lc, rc]: 当前节点包含的区间
        // [l, r]: 修改区间

        // 当前区间是修改区间的子区间
        if (l <= lc && rc <= r)
        {
            tr[p].add += val;
            tr[p].max += val;
            return;
        }
        // 如果要访问节点n的孩子节点, 就需要创建其孩子节点
        lazycreate(p);
        pushdown(p);   // 下放数据
        int mid = lc + rc >> 1;
        if (l <= mid)
            update(tr[p].lc, lc, mid, l, r, val);
        if (r > mid)
            update(tr[p].rc, mid + 1, rc, l, r, val);
        pushup(p); // 从子节点更新当前节点数据
        return;
    }

    int query(int p, int lc, int rc, int l, int r)
    {
        // p: 当前节点的编号
        // [s, t]: 当前节点包含的区间
        // [l, r]: 查询区间

        // 当前区间是查询区间的子集
        if (l <= lc && rc <= r)
            return tr[p].max;

        lazycreate(p);
        pushdown(p);
        int mid = lc + rc >> 1, ans = 0;
        if (l <= mid)
            ans = query(tr[p].lc, lc, mid, l, r);
        if (r > mid)
            ans = max(ans, query(tr[p].rc, mid + 1, rc, l, r));
        return ans;
    }

    // 访问到第p个节点, 创建其左右孩子
    void lazycreate(int p)
    {
        if (tr[p].lc == 0)
            tr[p].lc = ++cnt;
        if (tr[p].rc == 0)
            tr[p].rc = ++cnt;
        return;
    }

    // 访问到第p个节点时, 下放数据
    void pushdown(int p)
    {
        tr[tr[p].lc].add += tr[p].add;
        tr[tr[p].lc].max += tr[p].add;
        tr[tr[p].rc].add += tr[p].add;
        tr[tr[p].rc].max += tr[p].add;
        tr[p].add = 0;
        return;
    }

    // 从子节点更新当前节点
    void pushup(int p)
    {
        tr[p].max = max(tr[tr[p].lc].max, tr[tr[p].rc].max);
        return;
    }

public:
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        update(1, 1, N + 1, start + 1, end, 1);
        return query(1, 1, N + 1, 1, N + 1);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int ls, rs;
        int max;
        int add;
    };
    int N = 1e9;
    const static int M = 4 * 1e4;
    Node tr[M] = {{0, 0, 0, 0}};
    int cnt = 1;

    void update(int p, int s, int t, int l, int r, int val)
    {
        if (l <= s && t <= r)
        {
            // tr[p].max += val;
            // tr[p].add += val;
            tr[p].max = max(tr[p].max, val);
            tr[p].add = max(tr[p].add, val);
            return;
        }
        lazycreate(p);
        pushdown(p);
        int mid = (s + t) >> 1;
        if (l <= mid)
        {
            update(tr[p].ls, s, mid, l, r, val);
        }
        if (mid < r)
        {
            update(tr[p].rs, mid + 1, t, l, r, val);
        }
        pushup(p);
        return;
    }

    void pushdown(int p)
    {
        tr[tr[p].ls].max = max(tr[tr[p].ls].max, tr[p].add);
        tr[tr[p].ls].add = max(tr[tr[p].ls].add, tr[p].add);
        tr[tr[p].rs].max = max(tr[tr[p].rs].max, tr[p].add);
        tr[tr[p].rs].add = max(tr[tr[p].rs].add, tr[p].add);
        tr[p].add = 0;
        return;
    }
    void pushup(int p)
    {
        tr[p].max = max(tr[tr[p].ls].max, tr[tr[p].rs].max);
        return;
    }
    int query(int p, int s, int t, int l, int r)
    {
        if (l <= s && t <= r)
        {
            return tr[p].max;
        }
        lazycreate(p);
        pushdown(p);
        int mid = (s + t) >> 1;
        int ans = 0;
        if (l <= mid)
        {
            ans = query(tr[p].ls, s, mid, l, r);
        }
        if (mid < r)
        {
            ans = max(ans, query(tr[p].rs, mid + 1, t, l, r));
        }

        return ans;
    }
    void lazycreate(int p)
    {
        if (tr[p].ls == 0)
        {
            tr[p].ls = ++cnt;
        }
        if (tr[p].rs == 0)
        {
            tr[p].rs = ++cnt;
        }
        return;
    }

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        int n = buildings.size();

        // 离散化
        set<int> st;
        for (int i = 0; i < buildings.size(); i++)
        {
            st.insert(buildings[i][0]);
            st.insert(buildings[i][1]);
        }
        unordered_map<int, int> mp;
        n = 0;
        for (auto &num : st)
        {
            mp[num] = ++n;
        }
        // cout << st.size() << endl;

        // 线段树
        for (int i = 0; i < buildings.size(); i++)
        {
            int l = mp[buildings[i][0]];
            int r = mp[buildings[i][1]];
            // cout << l << ' ' << r << endl;

            // 注意, 这里不是往上加, 而是覆盖
            update(1, 1, N + 1, l, r - 1, buildings[i][2]);
        }

        vector<vector<int>> ans;
        int temp = 0;
        for (auto &num : st)
        {
            // 单点查询
            int cur = query(1, 1, N + 1, mp[num], mp[num]);
            // int cur = query(1, 1, N + 1, num, num);
            if (cur != temp)
            {
                ans.push_back({num, cur});
                temp = cur;
            }
            // ans.push_back({num, cur});
        }

        return ans;
    }
};
// @lc code=end

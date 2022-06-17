/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] Falling Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        // 表示从key开始, 高度都是value
        map<int, int> mp;
        mp[0] = 0;  // 初始全为0

        int n = positions.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            // [l, r]: 当前方块所在的区间
            int l = positions[i][0], r = l + positions[i][1] - 1;

            // 可能与区间[l, r]相交的区间
            // upper_bound(num): 返回第一个大于num的地址
            auto lp = mp.upper_bound(l), rp = mp.upper_bound(r);

            // 当前区间的右端点可能切割旧区间, 剩余部分保持不变
            int pre = prev(rp)->second;

            // 计算当前方块落下后的最高高度
            int h = 0;
            for (auto p = prev(lp); p != rp; p++)
            {
                h = max(h, p->second + positions[i][1]);
            }

            // 移除旧的高度
            mp.erase(lp, rp);
            // 增加新的高度, 表示从l开始, 高度为h
            mp[l] = h;

            // 当前区间只影响[l, r], r之后的高度保持不变
            if (rp == mp.end() || rp->first != r + 1)
            {
                mp[r + 1] = pre;
            }

            ans[i] = i > 0 ? max(ans[i - 1], h) : h;
        }

        return ans;

    }
};
// @lc code=end


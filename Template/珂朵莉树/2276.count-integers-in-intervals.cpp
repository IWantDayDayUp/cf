/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
public:
    int cnt = 0;
    // key: right
    // value: left
    map<int, int> mp;

    CountIntervals() {

    }
    
    void add(int left, int right) {
        int l = left, r = right;

        // 寻找第一个可能相交的区间
        auto it = mp.lower_bound(left);

        // 合并区间
        while (it != mp.end() && it->second <= right)
        {
            l = min(l, it->second);
            r = max(r, it->first);

            // 删掉旧的区间, 更新整数个数
            cnt -= it->first - it->second + 1;
            mp.erase(it++);
        }

        // 增加合并后的大区间
        cnt += r - l + 1;
        mp[r] = l;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end


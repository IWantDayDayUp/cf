/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class RangeModule {
public:
    map<int, int> mp;
    RangeModule() {

    }
    
    void addRange(int left, int right) {
        int l = left, r = right;
        auto it = mp.lower_bound(left);

        while (it != mp.end() && it->second <= right)
        {
            l = min(l, it->second);
            r = max(r, it->first);

            mp.erase(it++);
        }

        mp[r] = l;
    }
    
    bool queryRange(int left, int right) {
        auto it = mp.lower_bound(left);
        if (it == mp.end()) return false;
        return it->second <= left && right <= it->first;
    }
    
    void removeRange(int left, int right) {
        auto it = mp.lower_bound(left + 1);

        while (it != mp.end() && it->second <= right)
        {
            // 当前区间的左端点切割旧区间, 保留前半部分
            if (it->second < left)
            {
                mp[left] = it->second;
            }

            // 当前区间的右端点切割旧区间, 保留后半部分
            if (it->first > right)
            {
                mp[it->first] = right;
                break;
            } else {
                mp.erase(it++);
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end


#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    // 离散化
    vector<long long> nums(n);
    set<long long> st;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];

        if (i + 1 > nums[i])
        {
            st.insert(i + 1);
            st.insert(nums[i]);
        }
    }

    long long cnt = 0;
    map<long long, long long> mp;
    for (auto & num : st)
    {
        mp[num] = ++cnt;
    }


    // 树状数组
    vector<long long> tree;

    auto lowbit = [&](long long x) {
        return x & -x;
    };
    
    auto query = [&](long long x) {
        long long ans = 0;
        for(long long i = x; i > 0; i -= lowbit(i))
            ans += tree[i];
        return ans;
    };

    auto update = [&](long long x, long long u) {
        for(long long i = x; i <= st.size() + 10; i += lowbit(i))
            tree[i] += u;
    };

    // BIT从1开始, 需要整体往右偏移
    tree.resize(st.size() + 10, 0);

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > nums[i - 1])
        {
            // cout << i << ' ' << nums[i - 1] << endl;
            // cout << "mp[nums[i - 1]]" << mp[nums[i - 1]] << endl;
            // cout << mp[i] << ' ' << mp[nums[i - 1]] << endl;
            ans += query(mp[nums[i - 1]]);
            // cout << "query:" << ' ' << query(mp[nums[i - 1]]) << endl;

            update(mp[i] + 1, 1);

        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}
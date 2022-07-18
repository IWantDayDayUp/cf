#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 存储桌面上卡片堆的最上数字(后面都被覆盖)
    set<int> st;

    // 记录数字i的卡片下覆盖的数字(为了一连串吃掉满足k的卡片堆)
    vector<int> under(n + 1, -1);
    // 记录数字i坐在卡片堆的卡片数量
    vector<int> cnt(n + 1);

    vector<int> ans(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        // 当前卡片上的数字
        int cur;
        cin >> cur;

        auto it = st.lower_bound(cur);

        // 表示当前卡片需要新开启一个卡片堆
        if (it == st.end())
        {
            cnt[cur] = 1;  // 新的卡片堆, 数量为1
            st.insert(cur);  // 加入当前所有卡片堆的最上数字集合
        } 
        // 表示当前卡片可以覆盖某个卡片堆
        else {
            under[cur] = *it;
            cnt[cur] = cnt[*it] + 1;
            st.erase(it);
            st.insert(cur);
        }

        if (cnt[cur] == k)
        {
            st.erase(cur);
            int c = 0;
            while (c++ < k)
            {
                ans[cur] = i + 1;
                cur = under[cur];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
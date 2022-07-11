#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    long long mx = 0, mn = 1e9 + 7;
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        mp[a[i]] += 1;
    }
    sort(a.begin(), a.end());

    // 存储所有能实现的结果
    set<long long> st;

    function<long long(long long, long long)> dfs = [&](long long l, long long r)
    {
        if (l == r)
        {
            st.insert(l * mp[l]);
            return l * mp[l];
        }
        long long mid = l + r >> 1;

        // 按第k位, 分为前一半与后一半
        int k = upper_bound(a.begin(), a.end(), mid) - a.begin();

        // 目前 [l, r] 子数组的 sum
        long long res = dfs(l, a[k - 1]) + dfs(a[k], r);
        st.insert(res);

        return res;
    };

    st.insert(dfs(mn, mx));

    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;

        cout << (st.count(s) ? "Yes" : "No") << endl;
    }
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
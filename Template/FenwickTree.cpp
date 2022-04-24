#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class BIT
{
private:
    int n;
    vector<int> tree;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x)
    {
        return x & (-x);
    }

    void update(int x, int val)
    {
        while (x <= n)
        {
            // ++tree[x];
            tree[x] += val;
            x += lowbit(x);
        }
    }

    int query(int x) const
    {
        int ans = 0;
        while (x)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // init BIT
    int n = 100;
    BIT bit(n + 1);
    
    // 单点更新
    int idx = 1, val = 1;
    bit.update(idx, val);

    // 区间更新
    int leftIdx = 2, rightIdx = 4;
    bit.update(leftIdx, val);
    bit.update(rightIdx, val);

    // 单点查询
    bit.query(4);
    // 区间查询
    bit.query(5) - bit.query(2);

    return 0;
}
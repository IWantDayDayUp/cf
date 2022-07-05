#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i > 0 && nums[i - 1] != nums[i])
        {
            cnt += 1;
        }
    }

    if (k == 1)
    {
        if (cnt > 1) 
        {
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        // 注意: 前置 '0' 不贡献总和, 但是贡献 '不同数字个数' !!!!!
        int ans = 1;
        cnt -= k;
        if (cnt > 0)
        {
            ans += cnt / (k - 1);
            ans += cnt % (k - 1) > 0 ? 1 : 0;
        }

        cout << ans << endl;
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
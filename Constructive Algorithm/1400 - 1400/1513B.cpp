#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int mod = 1e9 + 7;

    int mn = *min_element(nums.begin(), nums.end());
    int cnt = 0;
    for (auto & num : nums)
    {
        if (num == mn)
        {
            cnt += 1;
        }
        if ((mn & num) != mn)
        {
            cout << 0 << endl;
            return ;
        }
    }

    int k = 1;
    for (int i = 1; i < n - 1; i++)
    {
        k = (1ll * k * i) % mod;
    }
    int ans = (1ll * cnt * (cnt - 1)) % mod;
    ans = (1ll * ans * k) % mod;
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
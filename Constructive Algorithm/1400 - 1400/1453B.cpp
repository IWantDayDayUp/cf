#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i > 0)
        {
            ans += abs(nums[i] - nums[i - 1]);
        }
    }

    int mx = max(abs(nums[0] - nums[1]), abs(nums[n - 2] - nums[n - 1]));
    for (int i = 1; i < n - 1; i++)
    {
        mx  = max(mx, abs(nums[i - 1] - nums[i]) + abs(nums[i] - nums[i + 1]) - abs(nums[i - 1] - nums[i + 1]));
    }

    cout << ans - mx << endl;
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
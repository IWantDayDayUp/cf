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
    sort(nums.begin(), nums.end(), [&](int a, int b)
    {
        return a > b;
    });
    vector<bool> have(n + 1, false);
    for (auto & num : nums)
    {
        while (num > n || have[num])
        {
            num /= 2;
        }
        if (num > 0)
        {
            have[num] = true;
        } else {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        nums[i] %= 3;
        mp[nums[i]] += 1;
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (mp[i] > n / 3)
        {
            int cur = mp[i] - n / 3;
            ans += cur;
            mp[(i + 1) % 3] += cur;
            mp[i] = n / 3;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (mp[i] > n / 3)
        {
            int cur = mp[i] - n / 3;
            ans += cur;
            mp[(i + 1) % 3] += cur;
            mp[i] = n / 3;
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
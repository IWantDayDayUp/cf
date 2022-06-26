#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    string s;
    cin >> s;

    vector<long long> prea(n, 0), preb(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            prea[i] = i == 0 ? nums[i] : nums[i] + prea[i - 1];
            preb[i] = i == 0 ? 0 : preb[i - 1];
        } else {
            prea[i] = i == 0 ? 0 : prea[i - 1];
            preb[i] = i == 0 ? nums[i] : nums[i] + preb[i - 1];
        }
    }

    vector<long long> sufa(n, 0), sufb(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'A')
        {
            sufa[i] = i == n - 1 ? nums[i] : nums[i] + sufa[i + 1];
            sufb[i] = i == n - 1 ? 0 : sufb[i + 1];
        } else {
            sufa[i] = i == n - 1 ? 0 : sufa[i + 1];
            sufb[i] = i == n - 1 ? nums[i] : nums[i] + sufb[i + 1];
        }
    }

    // cout << prea[n - 1] << ' ' << preb[n - 1] << endl;
    // 可以不变化

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (s[i] == 'A')
            {
                // {不变, 变前缀, 变后缀}
                ans = max(ans, max({sufb[0], prea[0] + sufb[0], preb[0] + sufa[0]}));
            } else {
                ans = max(ans, max({sufb[0], prea[0] + sufb[0] - nums[0], preb[0] + sufa[0] - nums[0]}));
            }
        } else if (i == n - 1)
        {
            if (s[i] == 'A')
            {
                ans = max(ans, max({sufb[0], prea[i], preb[i] + nums[i]}));
            } else {
                ans = max(ans, max({sufb[0], prea[i], preb[i] - nums[i]}));
            }
        } else {
            if (s[i] == 'A')
            {
                ans = max(ans, max({sufb[0], prea[i] + sufb[i], preb[i] + sufa[i]}));
            } else {
                ans = max(ans, max({sufb[0], prea[i] + sufb[i] - nums[i], preb[i] + sufa[i] - nums[i]}));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
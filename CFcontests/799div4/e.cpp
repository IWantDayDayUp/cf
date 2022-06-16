#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove()
{
    int n, s;
    cin >> n >> s;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int cur = 0;
    int ans = n + 1;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && cur + nums[j] <= s)
        {
            cur += nums[j];
            j += 1;
        }
        if (cur == s)
        {
            ans = min(ans, n - (j - i));
        }

        cur -= nums[i];
    }

    cout << (ans > n ? -1 : ans) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }

    return 0;
}
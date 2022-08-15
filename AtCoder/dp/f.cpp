#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    s = "1" + s;
    t = "1" + t;

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }
    // for (int j = 0; j <= m; j++)
    // {
    //     dp[0][j] = 0;
    // }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";

    function<void(int, int)> getans = [&](int i, int j)
    {
        if (i == 0 || j == 0)
        {
            return ;
        }

        if (s[i] == t[j])
        {
            ans += s[i];
            getans(i - 1, j - 1);
        } else if (dp[i][j] == dp[i][j - 1])
        {
            getans(i, j - 1);
        } else {
            getans(i - 1, j);
        }
    };

    getans(n - 1, m - 1);

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
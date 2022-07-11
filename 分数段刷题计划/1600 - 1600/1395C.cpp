#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(1 << 9));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (1 << 9); ++j)
        {
            if (!dp[i][j])
                continue;
            for (int k = 0; k < m; ++k)
                dp[i + 1][j | (a[i] & b[k])] = 1;
        }
    }

    int x = 0;
    while (!dp[n][x])
        ++x;

    cout << x << "\n";
    
    return 0;
}
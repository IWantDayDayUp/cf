#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    string s;
    cin >> x >> y >> z >> s;

    vector<vector<long long>> dp(s.size() + 1, vector<long long>(2, 1e18));
    dp[0][0] = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int cur = s[i] == 'a' ? 0 : 1;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                long long v = dp[i][j];
                if (j != k) 
                {
                    v += z;
                }
                if (cur == k)
                {
                    v += x;
                } else {
                    v += y;
                }

                dp[i + 1][k] = min(dp[i + 1][k], v);
            }
        }
    }

    cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int cmp(char a, char b) {
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int r = 0; r <= n; r++) {
        for (int l = r; l >= 0; l--) {
            if (l == r) {
                dp[l][r] = 0;
            } else if (r - l >= 2) {
                // Alice先取左边第一个, Bob可以取左边第二个, 或者右边第一个
                int v1 = dp[l + 1][r - 1] != 0 ? dp[l + 1][r - 1] : cmp(s[l], s[r - 1]);
                int v2 = dp[l + 2][r] != 0 ? dp[l + 2][r] : cmp(s[l], s[l + 1]);

                // Alice先取右边第一个, Bob可以取左边第一个, 或者右边第二个
                int v3 = dp[l + 1][r - 1] != 0 ? dp[l + 1][r - 1] : cmp(s[r - 1], s[l]);
                int v4 = dp[l][r - 2] != 0 ? dp[l][r - 2] : cmp(s[r - 1], s[r - 2]);

                // Bob肯定是要从剩余的两个选择中, 选择小的(-1表示Bob赢)
                // 而Alice要选择大的(1表示Alice赢)
                dp[l][r] = max(min(v1, v2), min(v3, v4));
            }
        }
    }
    
    int ans;
    
    if (n % 2 == 0) {
        ans = dp[0][n];
    } else {
        ans = min(dp[0][n - 1], dp[1][n]);
        if (ans == 0) {
            ans = 1;
        }
    }
    
    cout << (ans == 1 ? "Alice" : ans == 0 ? "Draw" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
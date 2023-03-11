#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> pre(26, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            pre[j][i + 1] += pre[j][i];
        }
        pre[s[i] - 'a'][i + 1] += 1;
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 26; k++)
            {
                int t = pre[k][j + 1] - pre[k][i];
                cnt += t * (t - 1) / 2;
            }

            // cout << i << ' ' << j << ' ' << cnt << endl;

            ans = max(ans, cnt * 1.0 / (j - i + 1));
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
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
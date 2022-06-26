#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    // n: zero
    // m: one

    if (n - 1 <= m && m <= 2 * (n + 1))
    {
        string ans = "";
        if (n - 1 == m)
        {
            ans += '0';
            for (int i = 0; i < m; i++)
            {
                ans += "10";
            }
        } else if (n == m)
        {
            for (int i = 0; i < n; i++)
            {
                ans += "10";
            }
        } else {
            int k = m % (n + 1);
            if (k == 0 && m == 2 * (n + 1)) k = n + 1;
            for (int i = 0; i < n; i++)
            {
                if (k > 0)
                {
                    ans += "110";
                } else {
                    ans += "10";
                }
                k -= 1;
            }
            if (k > 0)
            {
                ans += "11";
            } else {
                ans += "1";
            }
        }

        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

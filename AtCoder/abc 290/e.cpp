#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        a[c].push_back(i + 1);
    }

    long long ans = 0;

    // 如果每个位置都改变(即使不需要), 总共需要的次数
    for (long long i = 0; i < n; i++)
    {
        ans += (i + 1) / 2 * (n - i);
    }

    // 减去不需要改变的次数
    for (long long i = 1; i<= n; i++)
    {
        long long l = 0, r = a[i].size() - 1;

        while (l < r)
        {
            if (a[i][l] < (n + 1 - a[i][r]))
            {
                ans -= (r - l) * a[i][l];
                l += 1;
            } else {
                ans -= (r - l) * (n + 1 - a[i][r]);
                r -= 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    array<long long, 2> dp{};
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x == 0)
        {
            dp[0] = max(dp[0], max(dp[0], dp[1]) + y);
        } else {
            dp[1] = max(dp[1], dp[0] + y);
        }
    }

    cout << max(dp[0], dp[1]) << endl;

    return 0;
}
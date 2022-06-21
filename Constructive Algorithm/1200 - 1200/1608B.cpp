#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b + 2 > n || abs(a - b) > 1)
    {
        cout << -1 << endl;
        return ;
    }

    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    if (a == b)
    {
        for (int i = 1; i <= a; i++)
        {
            swap(ans[2 * i], ans[2 * i + 1]);
        }
    } else if (a > b)
    {
        for (int i = 1; i <= a; i++)
        {
            swap(ans[n - 2 * i + 2], ans[n - 2 * i + 1]);
        }
    } else {
        for (int i = 1; i <= b; i++)
        {
            swap(ans[2 * i - 1], ans[2 * i]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}

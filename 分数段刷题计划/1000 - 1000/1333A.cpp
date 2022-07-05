#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<string> ans(n, string(m, 'B'));
    ans[n - 1] = string(m, 'W');
    ans[n - 1][m - 1] = 'B';

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
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
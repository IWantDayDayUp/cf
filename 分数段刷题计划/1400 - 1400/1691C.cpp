#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt = 0;
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') continue;
        cnt += 1;
        if (left == -1)
        {
            left = i;
        }
        right = i;
    }

    int ans = 0;

    // move to last
    if (cnt > 0 && k >= (n - 1 - right))
    {
        k -= n - 1 - right;
        cnt -= 1;

        ans += 1;
    }
    // move to first
    if (cnt > 0 && k >= left)
    {
        k -= left;
        cnt -= 1;

        ans += 10;
    }

    cout << ans + 11 * cnt << endl;
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
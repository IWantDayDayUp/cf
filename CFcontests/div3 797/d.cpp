#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            if (s[i] == 'W')
            {
                cnt += 1;
            }
        } else {
            ans = min(ans, cnt);
            if (s[i] == 'W')
            {
                cnt += 1;
            }
            if (s[i - k] == 'W')
            {
                cnt -= 1;
            }
        }
    }

    ans = min(ans, cnt);

    cout << ans << endl;
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
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, k;
    cin >> n >> k;
    
    int cnt = 0;
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cin >> pre;
        } else {
            int cur;
            cin >> cur;

            if (pre < cur * 2)
            {
                cnt += 1;

                if (cnt >= k)
                {
                    ans += 1;
                }
            } else {
                cnt = 0;
            }

            pre = cur;
        }
    }

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
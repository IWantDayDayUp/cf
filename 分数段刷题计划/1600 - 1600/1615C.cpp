#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << endl;
    } else {
        int ans = n + 1;

        for (auto c : {0, 1})
        {
            vector<int> goal(n);
            for (int i = 0; i < n; i++)
            {
                goal[i] = b[i] - '0';
                goal[i] ^= c;
            }

            int cnt[2] = {};
            for (int i = 0; i < n; i++)
            {
                int x = a[i] - '0';
                if (x != goal[i])
                {
                    cnt[x] += 1;
                }
            }

            if ((cnt[0] == cnt[1] || cnt[0] == cnt[1] - 1) && (cnt[0] + cnt[1]) % 2 == c)
            {
                ans = min(ans, cnt[0] + cnt[1]);
            }
        }
        
        cout << (ans > n ? -1 : ans) << endl;
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
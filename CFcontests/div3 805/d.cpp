#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    string s;
    cin >> s;
    int p;
    cin >> p;

    vector<int> cnt(26);
    int cur = 0;
    for (auto & c : s)
    {
        cnt[c - 'a'] += 1;
        cur += (c - 'a') + 1;
    }

    if (cur <= p)
    {
        cout << s << endl;
    } else {
        // cout << "cur:" << ' ' << cur << endl;
        vector<bool> ok(26, true);
        int i = 25;
        while (cur > p && i >= 0)
        {
            cur -= (i + 1) * cnt[i];
            ok[i] = false;
            i -= 1;
        }

        if (cur <= p)
        {
            i += 1;
        }

        ok[i] = true;

        // cout << "cur: " << cur << endl;
        int num = (p - cur) / (i + 1);

        string ans = "";
        // cout << "YES" << endl;
        for (auto c : s)
        {
            if (ok[c - 'a'] == false && c != 'a' + i)
            {
                continue;
            } else if (c == 'a' + i)
            {
                num -= 1;
                if (num >= 0)
                {
                    ans += c;
                }
            } else {
                ans += c;
            }
        }

        cout << ans << endl;
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
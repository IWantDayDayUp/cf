#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    int pre = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
           
            if (i - pre > 1)
            {
                ans += 1;
                pre = i;
            } else {
                pre = i;
            }
        }
    }

    if (pre != n - 1)
    {
        ans += 1;
    }

    cout << (ans >= 3 ? 2 : ans) << endl;
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
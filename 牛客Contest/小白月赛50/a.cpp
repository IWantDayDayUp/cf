#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;

        if (i > 0)
        {
            if (cur > pre * k || cur * k < pre)
            {
                ans += 1;
            }
        }
        pre = cur;
    }

    cout << ans << endl;

    return 0;
}
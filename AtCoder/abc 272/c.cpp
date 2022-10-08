#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long even1 = -1, even2 = -1;
    long long odd1 = -1, odd2 = -1;

    for (int i = 0; i < n; i++)
    {
        long long cur;
        cin >> cur;

        if (cur % 2 == 0)
        {
            if (cur > even1)
            {
                even2 = even1;
                even1 = cur;
            } else if (cur > even2) {
                even2 = cur;
            }
        } else {
            if (cur > odd1)
            {
                odd2 = odd1;
                odd1 = cur;
            }
            else if (cur > odd2) {
                odd2 = cur;
            }
        }
    }

    long long ans = -1;
    if (even1 > -1 && even2 > -1)
    {
        ans = even1 + even2;
    }
    if (odd1 > - 1 && odd2 > -1)
    {
        ans = max(ans, odd1 + odd2);
    }

    cout << ans << endl;

    return 0;
}
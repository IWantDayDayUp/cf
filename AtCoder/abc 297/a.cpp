#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    int pre = -1, ans = -1;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;

        if (pre != -1 && ans == -1 && c - pre <= d)
        {
            ans = c;
        }

        pre = c;
    }

    cout << ans << endl;

    return 0;
}
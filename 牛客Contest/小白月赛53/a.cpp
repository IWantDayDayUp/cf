#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }

    int need;
    cin >> need;

    for (int i = 0; i < 4; i++)
    {
        int ans = 0;

        if (need > a[i])
        {
            ans = need - a[i];
        }

        cout << ans << " \n"[i == 3];
    }

    return 0;
}
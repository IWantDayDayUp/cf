#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if (x == 0 && y > 0)
    {
        swap(x, y);
    } else if (x > 0 && y == 0)
    {
        
    } else {
        cout << -1 << endl;
        return;
    }

    if ((n - 1) % x != 0)
    {
        cout << -1 << endl;
        return;
    }

    int ans = 1;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans << " \n"[i == n - 2];
        cnt += 1;
        if (cnt >= x)
        {
            ans = i + 3;
            cnt = 0;
        }
    }
            

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
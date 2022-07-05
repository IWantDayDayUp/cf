#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << -1 << endl;
    } else {
        string ans = string(n - 1, '3');

        ans = '2' + ans;

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
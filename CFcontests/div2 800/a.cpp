#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int a, b;
    cin >> a >> b;

    string ans = "";
    for (int i = 0; i < min(a, b); i++)
    {
        ans += "01";
    }
    for (int i = 0; i < abs(a - b); i++)
    {
        ans += a > b ? '0' : '1';
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
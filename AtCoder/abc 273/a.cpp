#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int pre = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = i * pre;
        pre = ans;
    }

    cout << ans << endl;

    return 0;
}
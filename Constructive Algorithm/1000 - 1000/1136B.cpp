#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    if (n == 2)
    {
        cout << 6 << endl;
    } else {
        cout << 3 * n + min(x - 1, n - x) << endl;
    }

    return 0;
}
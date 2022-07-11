#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int s = a + b + c + d;
    if (s == 0)
    {
        cout << 0 << endl;
    } else if (s == 1) {
        cout << 1 << endl;
    } else if (s == 2)
    {
        cout << 1 << endl;
    } else if (s == 3)
    {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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
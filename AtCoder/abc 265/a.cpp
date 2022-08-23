#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    if (y / 3 > x)
    {
        cout << n * x << endl;
    } else {
        cout << (n / 3) * y + (n % 3) * x << endl;
    }

    return 0;
}
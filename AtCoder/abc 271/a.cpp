#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int x = n / 16, y = n % 16;

    if (x <= 9)
    {
        cout << x;
    } else {
        cout << char('A' + x - 10);
    }

    if (y <= 9)
    {
        cout << y;
    } else {
        cout << char('A' + y - 10);
    }

    return 0;
}
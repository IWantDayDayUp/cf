#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    auto check = [&](int a, int b, int c, int d, int e, int f)
    {
        int x = a * d - b * c;
        int y = a * f - b * e;

        return x * y >= 0;
    };

    if (!check(x2 - x1, y2 - y1, x3 - x1, y3 - y1, x4 - x1, y4 - y1))
    {
        cout << "No" << endl;
    } else if (!check(x3 - x2, y3 - y2, x4 - x2, y4 - y2, x1 - x2, y1 - y2))
    {
        cout << "No" << endl;
    } else if (!check(x4 - x3, y4 - y3, x2 - x3, y2 - y3, x1 - x3, y1 - y3))
    {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
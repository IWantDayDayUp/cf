#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if (x > 7)
    {
        x = 14 - x;
    }
    if (y > 7)
    {
        y = 14 - y;
    }

    if (x <= y)
    {
        if (x % 2 == 0)
        {
            cout << "black" << endl;
        } else {
            cout << "white" << endl;
        }
    } else {
        if (y % 2 == 0)
        {
            cout << "black" << endl;
        } else {
            cout << "white" << endl;
        }
    }

    return 0;
}
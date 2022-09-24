#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    if (x <= y && y <= z)
    {
        if (0 <= y)
        {
            cout << abs(x - 0) << endl;
        } else if (0 <= z)
        {
            cout << abs(0 - z) + abs(z - x) << endl;
        } else {
            cout << abs(0 - x) << endl;
        }
    } else if (x <= z && z <= y)
    {
        if (0 <= y)
        {
            cout << abs(x - 0) << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (z <= x && x <= y)
    {
        if (0 <= y)
        {
            cout << abs(x - 0) << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (z <= y && y <= x)
    {
        if (0 <= z)
        {
            cout << abs(x - 0) << endl;
        } else if (0 <= y)
        {
            cout << abs(0 - z) + abs(x - z) << endl;
        } else {
            cout << abs(x - 0) << endl;
        }
    } else if (y <= x && x <= z)
    {
        if (0 <= y)
        {
            cout << -1 << endl;
        } else {
            cout << abs(x - 0) << endl;
        }
    } else if (y <= z && z <= x)
    {
        if (0 <= y)
        {
            cout << -1 << endl;
        } else {
            cout << abs(x - 0) << endl;
        }
    }

    return 0;
}
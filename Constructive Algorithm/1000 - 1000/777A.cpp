#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    n %= 6;

    if (n == 0)
    {
        cout << x << endl;
    } else {
        while (n)
        {
            if (n % 2 == 0)
            {
                if (x == 2) x = 1;
                else if (x == 1) x = 2;
            } else {
                if (x == 0) x = 1;
                else if (x == 1) x = 0;
            }
            n -= 1;
        }

        cout << x << endl;
    }

    return 0;
}
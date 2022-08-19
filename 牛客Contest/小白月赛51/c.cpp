#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, x;
    cin >> a >> b >> x;

    if (a < x / 2 || b < x / 2)
    {
        cout << -1 << endl;
    } else {
        a -= x / 2;
        b -= x / 2;

        if (a % 2 || b % 2)
        {
            cout << -1 << endl;
        } else 
        {
            cout << string(a, '0');
            for (int i = 0; i < x / 2; i++)
            {
                cout << "01";
            }
            cout << string(b, '1');
        }
    }

    return 0;
}
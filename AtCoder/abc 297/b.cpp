#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int b1 = -1, b2 = -1, k = -1, r1 = -1, r2 = -1;
    for (int i = 0; i < 8; i++)
    {
        if (s[i] == 'B')
        {
            if (b1 != -1)
            {
                b2 = i;
            } else {
                b1 = i;
            }
        } else if (s[i] == 'K')
        {
            k = i;
        } else if (s[i] == 'R')
        {
            if (r1 != -1)
            {
                r2 = i;
            } else {
                r1 = i;
            }
        }
    }

    cout << (((b1 % 2 != b2 % 2) && r1 < k && k < r2) ? "Yes" : "No") << endl;

    return 0;
}